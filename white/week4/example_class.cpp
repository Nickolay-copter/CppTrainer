#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

double ComputeImageWeight(const Params& params, const Image& image){
    double weight = image.quality;
    weight -= image.freshness * params.a + params.b;
    weight += image.rating * params.c;
    return weight;
}

double ComputeQualityByWeight(const Params& params, const Image& image, double weight){
    double quality = weight;
    quality -= image.rating * params.c;
    quality += image.freshness * params.a + params.b;
    return quality;
}

