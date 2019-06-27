#include "YTFaceRetrieve.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <sys/time.h>
#include <pthread.h>

#include "ytcommon.h"
using namespace std;
using namespace yt_backend_face_retrieve;


YTFaceRetrieve face_retrieve;

struct feature_info {
	std::vector<FEATURE_ITEM> feature_data;
	std::string feature_name;
	int libIndex;
};

int load_feature(std::vector<FEATURE_ITEM>& feat, int i)
{
	string part1 = "features/feat";
	string part3 = ".txt";
	int part2 = i;

	ostringstream oss;
	oss << part1 << part2 << part3;
	ifstream infile(oss.str());
	if (!infile)
	{
		throw runtime_error("file can not open");
		return -1;
	}
	else
	{
		string s;
		while(!infile.eof())
		{
			getline(infile, s);
			feat.push_back(atof(s.c_str()));
		}
	}
	// cout << "Load feature successed!" << endl;
	return 0;
}


int set_libs(std::vector<FEATURE_ITEM>& feat, std::vector<string>& face_ids){

	string part1 = "features/feat";
	int part2;
	string part3 = ".txt";
	for (int i = 0; i < 10; ++i)
	{	
		part2 = i;
		ostringstream oss;
		oss<< part1 << part2 << part3;
		ifstream infile(oss.str());
		if (!infile)
		{
			throw runtime_error("file can not open");
			return -1;
		}
		else
		{
			string s;
			while(!infile.eof())
			{
				getline(infile, s);
				feat.push_back(atof(s.c_str()));
			}
		}
	}
    
    part1 = "test_";
	//1号lib中拥有10张人脸数据
	for (int i = 0; i < 10; ++i)
	{
		part2 = i;
		ostringstream oss;
		oss << part1 << part2;
		face_ids.push_back(oss.str());
	}
	return 0;
}


void *insertFeature(void *threadarg)
{
	// cout << "To insert feature... ";
	struct feature_info *my_data = (struct feature_info *) threadarg;

	face_retrieve.insertSingleFeature(my_data -> feature_data, my_data -> feature_name, my_data -> libIndex);
	// cout << my_data -> feature_name << endl;
	
	// pthread_exit(NULL);
	return NULL;
}


int main(int argc, char const *argv[])
{
	int authInitRet = YTCommon::initAuth("../../dev_jianqiang.lic");
    cout << "auth ret : "<< authInitRet <<endl;

	// YTFaceRetrieve face_retrieve;

	face_retrieve.loadConvertTable("cvt_table");

	//预先设定好的人脸库，测试只有一个人脸特征库 1
	std::vector<int > lib;
	lib.push_back(1);

	std::vector<float> feature;
	std::vector<string> face_ids;
	set_libs(feature, face_ids);

	int ret = face_retrieve.createLibs(feature, face_ids, 1024, 1);

	// 清空1号人脸库
	face_retrieve.clearLib(1);

    // 清空所有人脸库
	face_retrieve.clearAllLibs();

    // 重新创建人脸库
	ret = face_retrieve.createLibs(feature, face_ids, 1024, 1);

	std::vector<int> query_libs = {1};
	int topN = 1;
	float threshold = 0.00001;
	// std::vector<float> feature;  //单独一个feature
	std::vector<std::vector<float>> features; //多个人脸的features,只测试一个



    // load query features
	std::vector<float> feat = {};

	load_feature(feat, 69);

	cout << "query feat dimension: " << feat.size() << " d" << endl;


	features.push_back(feat);

	std::vector<RetrieveResultItem> result;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	cout << "query features size:" << features.size() << endl;
	for (int i = 0; i < features.size(); ++i)
	{	
		ret = face_retrieve.retrieve(query_libs, topN, features[i], result, threshold);
	}
	gettimeofday(&end, NULL);
	float usetime = (int)((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000);

	cout<< "Retrieve cost : " << usetime << " ms! result size:" << result.size()<<endl;

	int i = 0;
	for (std::vector<RetrieveResultItem>::iterator 
              it = result.begin();it != result.end(); ++it) {
			cout << "retrieval result " << ++i << ": ";
			cout << (*it).face_id<< " ";
			cout << (*it).score<< " ";
			cout << (int)((*it).lib_id)<< endl;
     }


    
	std::cout << "About to insertSingleFeature" << std::endl;

	pthread_t threads[10];
	struct feature_info fi[10];
	int rc;

	string part1 = "test_";
	int part2;

	for(int i = 0; i < 10; i++)
	{
		// cout << "main() : creating thread, " << i << endl;
		load_feature(fi[i].feature_data, i+40);
		ostringstream oss;
		part2 = i+40;
		oss << part1 << part2;
		fi[i].feature_name = oss.str();

		fi[i].libIndex = 1;

		rc = pthread_create(&threads[i], NULL, insertFeature, (void *)&fi[i]);
		if (rc)
		{
			cout << "Error: unable to create thread," << rc << endl;
			exit(-1);
		}
	}
	// pthread_exit(NULL);

    for (int i = 0; i < 9; i++){
        pthread_join(threads[i], NULL);
    }


	// face_retrieve.insertSingleFeature(feat_all_1, "face_all_1", 1);


	std::vector<FEATURE_ITEM> feat_all = {};
	std::vector<std::string> face_ids_all = {};
    face_retrieve.getAllFeatures(feat_all, face_ids_all, 1);

    // 输出getAllFeatures的结果(add by jianqiang)
    for(std::vector<string>::iterator it = face_ids_all.begin(); it != face_ids_all.end(); ++it)
    {
    	cout << *it << endl;
    }


    //querySingleFeature
    std::vector<float> feat_temp = {};
	face_retrieve.querySingleFeature(feat_temp, "test_1", 1);
	// 输出query结果feat_temp
	// for (int i = 0; i < 1024; ++i)
	// {
	// 	cout<<feat_temp[i]<<" ";
	// }
	// cout << endl;

    //changeSingleFeature
    std::vector<float> feat_all_2 = {};
    part1 = "features/feat";
	string part3 = ".txt";
	part2 = 71;
	ostringstream oss2;
	oss2<< part1 << part2 << part3;
	ifstream infile2(oss2.str());
	if (!infile2)
	{
		throw runtime_error("file can not open");
		return -1;
	}
	else
	{
		string s;
		while(!infile2.eof())
		{
			getline(infile2, s);
			feat_all_2.push_back(atof(s.c_str()));
		}
	}
	std::cout<<"feat_all_2: "<<feat_all_2[0]<<" "<<feat_all_2[1]<<std::endl;
    face_retrieve.changeSingleFeature(feat_all_2, "test_1", 1);

    feat_all = {};
    face_ids_all = {};
    face_retrieve.getAllFeatures(feat_all, face_ids_all, 1);

    //deleteSingleFeature
	face_retrieve.deleteSingleFeature("test_1", 1);

    //getAllFeatures
    feat_all = {};
    face_ids_all = {};
    face_retrieve.getAllFeatures(feat_all, face_ids_all, 1);
    
    // // 输出getAllFeatures的结果(add by jianqiang)
    // for(std::vector<string>::iterator it = face_ids_all.begin(); it != face_ids_all.end(); ++it)
    // {
    // 	cout << *it << endl;
    // }

	return 0;
}














