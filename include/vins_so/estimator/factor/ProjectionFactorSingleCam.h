#ifndef PROJECTIONFACTORSingleCam_H
#define PROJECTIONFACTORSingleCam_H

#include "vins_so/utility/utility.h"
#include <Eigen/Dense>
#include <ceres/ceres.h>
#include <code_utils/sys_utils/tic_toc.h>

#define UNIT_SPHERE_ERROR

class ProjectionFactorSingleCam : public ceres::SizedCostFunction< 2, 7, 7, 1, 7 >
{
    public:
    ProjectionFactorSingleCam( const Eigen::Vector3d& _pts_i, const Eigen::Vector3d& _pts_j, const double& err );

    virtual bool Evaluate( double const* const* parameters, double* residuals, double** jacobians ) const;

    void check( double** parameters ) {}

    public:
    Eigen::Vector3d pts_i, pts_j;
    Eigen::Matrix< double, 2, 3 > tangent_base;
    Eigen::Matrix2d sqrt_info;
    static double sum_t;
};

#endif // PROJECTIONFACTORSingleCam_H
