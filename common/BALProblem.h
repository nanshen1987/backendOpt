//
// Created by root on 18-8-20.
//

#ifndef BACKENDOPT_BALPROBLEM_H
#define BACKENDOPT_BALPROBLEM_H

#include <cstdio>
#include<string>
#include <iostream>

namespace lmars{
    class BALProblem {

    public:
        explicit BALProblem(const std::string& filename, bool  use_quaternions);
        ~BALProblem(){
            delete[] point_index_;
            delete[] camer_index_;
            delete[] observations_;
            delete[] parameters_;
        }

        void WriteToFile(const std::string& fileName) const ;
        void WriteToPLYFile(const std::string& fileName) const ;
        void Normalize();
        void Perturb(const double rotation_sigma, const double translation_sigma, const double point_sigma);


        int camera_block_size() const { return use_quaternions_?10:9;}
        int point_block_size() const{ return 3;}

        int getNum_cameras_() const {
            return num_cameras_;
        }

        int getNum_points_() const {
            return num_points_;
        }

        int getNum_observations_() const {
            return num_observations_;
        }

        int getNum_parameters_() const {
            return num_parameters_;
        }

    private:
        void CameraToAngelAxisAndCenter(const double* camera, double *axis_angel, double*center) const ;
        void AngelAxisAndCenterToCamera(const double *axis_angel, const double*center,double* camera)const;
        int num_cameras_;
        int num_points_;
        int num_observations_;
        int num_parameters_;
        bool use_quaternions_;
        int* point_index_;
        int* camer_index_;
        double * observations_;
        double * parameters_;
    };
}

#endif //BACKENDOPT_BALPROBLEM_H
