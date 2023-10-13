#include <iostream>
#include <cmath>
#include <vector>

// 计算向量的模长
float vectorMagnitude(const std::vector<float>& vec) {
	float sum = 0.0f;
	for (float element : vec) {
		sum += element * element;
	}
	return std::sqrt(sum);
}

// 计算两个向量的内积
float dotProduct(const std::vector<float>& vec1, const std::vector<float>& vec2) {
	float product = 0.0f;
	for (int i = 0; i < vec1.size(); i++) {
		product += vec1[i] * vec2[i];
	}
	return product;
}

// 计算余弦相似度
float cosineSimilarity(const std::vector<float>& vec1, const std::vector<float>& vec2) {
	// 计算两个向量的模长
	float magnitude1 = vectorMagnitude(vec1);
	float magnitude2 = vectorMagnitude(vec2);

	// 如果其中一个向量的模长为0，则相似度为0
	if (magnitude1 == 0 || magnitude2 == 0) {
		return 0;
	}

	// 计算两个向量的内积
	float product = dotProduct(vec1, vec2);

	// 计算余弦相似度
	return product / (magnitude1 * magnitude2);
}

int main() {
	float lat1 = 30.114514;
	float lon1 = 120.112233;

	float lat2 = 30.114552;
	float lon2 = 120.112244;

	float lat3 = 30.114521;
	float lon3 = 120.112239;

	float lat4 = 30.114511;
	float lon4 = 120.112227;

	std::vector<float> vec1 = { lat2 - lat1, lon2 - lon1};
	//std::vector<float> vec2 = { 3.0, 4.0 };
	std::vector<float> vec2 = { lat4 - lat3, lon4 - lon3 };

	float similarity = cosineSimilarity(vec1, vec2);

	std::cout << "两个向量的余弦相似度为: " << similarity << std::endl;

	return 0;
}
