#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

namespace SoftUni {

    class Resource {
        int id;
        ResourceType resourceType;
        std::string link;

        friend std::istream &operator>>(std::istream &is, Resource &lecture);
        friend std::ostream& operator<<(std::ostream& os, const Resource& resource);

    public:
        int getId() const {
            return this->id;
        }

        ResourceType getResourceType() const {
            return this->resourceType;
        }
    };

    std::istream &operator>>(std::istream &is, Resource &lecture) {
        std::string resourceTypeStr;
        is >> lecture.id >> resourceTypeStr >> lecture.link;

        if (resourceTypeStr == "Presentation")
            lecture.resourceType = ResourceType::PRESENTATION;
        else if (resourceTypeStr == "Demo")
            lecture.resourceType = ResourceType::DEMO;
        else if (resourceTypeStr == "Video")
            lecture.resourceType = ResourceType::VIDEO;

        return is;
    }

    std::ostream& operator<<(std::ostream& os, const Resource& resource) {
        return os << resource.getId() << ' ' << resource.resourceType << ' ' << resource.link;
    }
}

#endif
