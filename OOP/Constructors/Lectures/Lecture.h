#ifndef LECTURE_H
#define LECTURE_H
#include <map>

namespace SoftUni {

    class Lecture {
        std::map<int, Resource> resources;

        friend Lecture& operator<<(Lecture& lecture, const Resource& resource);
        friend std::vector<ResourceType>& operator<<(std::vector<ResourceType>& resourceTypes, const Lecture& lecture);
    public:
        class Iterator {
            std::map<int, Resource>::iterator it;
        public:
            Iterator(std::map<int, Resource>::iterator it) : it(it) {}

            Iterator& operator++() {
                ++it;
                return *this;
            }

            Iterator operator++(int) {
                Iterator temp(*this);
                ++it;
                return temp;
            }

            Resource& operator*() const {
                return it->second;
            }

            bool operator==(const Iterator& other) const {
                return it == other.it;
            }

            bool operator!=(const Iterator& other) const {
                return it != other.it;
            }
        };

        Iterator begin() {
            return Iterator(resources.begin());
        }

        Iterator end() {
            return Iterator(resources.end());
        }

        int operator[](ResourceType& resourceType) const {
            int numberOfResourceTypes{};
            for (const std::pair<const int, Resource>& resourcePair : resources)
                if (resourcePair.second.getResourceType() == resourceType)
                    ++numberOfResourceTypes;
            return numberOfResourceTypes;
        }
    };

    Lecture& operator<<(Lecture& lecture, const Resource& resource) {
        lecture.resources[resource.getId()] = resource;
        return lecture;
    }

    std::vector<ResourceType>& operator<<(std::vector<ResourceType>& resourceTypes, const Lecture& lecture) {
        std::set<ResourceType> usedResourceTypes;

        for (const std::pair<const int, Resource>& resourcePair : lecture.resources) {
            ResourceType currentResType = resourcePair.second.getResourceType();
            if (usedResourceTypes.find(currentResType) == usedResourceTypes.end()) {
                usedResourceTypes.insert(currentResType);
            }
        }

        if (usedResourceTypes.find(ResourceType::PRESENTATION) != usedResourceTypes.end())
            resourceTypes.push_back(ResourceType::PRESENTATION);
        if (usedResourceTypes.find(ResourceType::DEMO) != usedResourceTypes.end())
            resourceTypes.push_back(ResourceType::DEMO);
        if (usedResourceTypes.find(ResourceType::VIDEO) != usedResourceTypes.end())
            resourceTypes.push_back(ResourceType::VIDEO);
        
        return resourceTypes;
    }
}

#endif
