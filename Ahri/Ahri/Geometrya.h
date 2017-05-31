#pragma once
#include "PluginSDK.h"
#include "cmath"
#include <map>
#define PI 3.14159265f

//CREDITS TO LEAGUESHARP COMMON GEOMETRY.H

 Vec2 ToVec2a(Vec3 vec)
{
	return Vec2(vec.x, vec.z);
}
 Vec3 ToVec3a(Vec2 vec)
{
	return Vec3(vec.x, 0, vec.y);
}
 Vec3 Normalizea(Vec3 x)
{
	auto X1 = ToVec2a(x);
	float sqr = X1.x * X1.x + X1.y * X1.y;
	return ToVec3a((X1 * (1.0f / sqrt(sqr))));
}
 Vec3 Pendiculara(Vec3 x)
{
	auto X1 = ToVec2a(x);
	Vec2 X2;
	X2.x = -X1.y;
	X2.y = X1.x;
	return ToVec3a(X2);
}

 float Distancea(Vec3 from, Vec3 to)
{
	return (from - to).Length2D();
}
 float AngleBetweena(Vec3 a, Vec3 center, Vec3 c)
{
	float a1 = Distancea(c, center);
	float b1 = Distancea(a, c);
	float c1 = Distancea(center, a);
	if (a1 == 0 || c1 == 0) { return 0; }
	else
	{
		return acos((a1 * a1 + c1 * c1 - b1 * b1) / (2 * a1 * c1)) * (180 / PI);
	}
}
 float AngleToRadian(float Angle)
{
	return Angle * PI / 180.f;
}
 Vec3 RotateAround(Vec3 pointToRotate3D, Vec3 centerPoint3D, float angleInDegree)
{
	auto angleInRadians = AngleToRadian(angleInDegree);
	double cosTheta = cos(angleInRadians);
	double sinTheta = sin(angleInRadians);
	Vec2 pointToRotate = ToVec2a(pointToRotate3D);
	Vec2 centerPoint = ToVec2a(centerPoint3D);
	Vec2 vec2Return
		(
			(cosTheta * (pointToRotate.x - centerPoint.x) -
				sinTheta * (pointToRotate.y - centerPoint.y) + centerPoint.x),

			(sinTheta * (pointToRotate.x - centerPoint.x) +
				cosTheta * (pointToRotate.y - centerPoint.y) + centerPoint.y)
			);
	return ToVec3a(vec2Return);
}
 bool InTheCone(Vec3 pos, Vec3 centerconePolar, Vec3 centerconeEnd, float coneAngle)

{

	return AngleBetweena(pos, centerconePolar, centerconeEnd) < coneAngle / 2

		&& Distancea(pos, centerconePolar) < Distancea(centerconePolar, centerconeEnd);

}
 float Distancea(Vec3 point, Vec3 segmentStart, Vec3 segmentEnd, bool onlyIfOnSegment = false)
{
	auto a = ToVec2a(point);
	auto b = ToVec2a(segmentStart);
	auto c = ToVec2a(segmentEnd);
	float STriangle = 0.5f * abs((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y));
	float botLength = Distancea(segmentStart, segmentEnd);
	float distance = 2 * STriangle / botLength;
	if (!onlyIfOnSegment)
		return distance;
	if (AngleBetweena(point, segmentStart, segmentEnd) > 90 || AngleBetweena(point, segmentEnd, segmentStart) > 90)
		return 100000.f;
	return distance;
}
 float Distancea(IUnit* from, IUnit* to)
{
	return (from->GetPosition() - to->GetPosition()).Length2D();
}
 float Distancea(IUnit* from, Vec3 to)
{
	return (from->GetPosition() - to).Length2D();
}
 float Distancea(Vec2 from, Vec2 to)
{
	return (from - to).Length();
}

 Vec3 Extenda(Vec3 from, Vec3 to, float distance)
{
	float realDistance = (from - to).Length() * distance / (from - to).Length2D();
	auto direction = (to - from).VectorNormalize();
	return from + direction * realDistance;
}
 std::vector<Vec3> GetCircleCircleIntersections(Vec3 center1, Vec3 center2, float radius1, float radius2)
{
	std::vector<Vec3> result;
	float D = Distancea(center2, center1);
	//The Circles dont intersect:
	if (D > radius1 + radius2 || (D <= abs(radius1 - radius2)))
	{
		return result;
	}

	float A = (radius1 * radius1 - radius2 * radius2 + D * D) / (2 * D);
	float H = sqrt(radius1 * radius1 - A * A);
	Vec3 Direction = (center2 - center1).VectorNormalize();
	Vec3 PA = ToVec3a(ToVec2a(center1) + A * ToVec2a(Direction));
	Vec3 S1 = ToVec3a(ToVec2a(PA) + H * ToVec2a(Pendiculara(Direction)));
	Vec3 S2 = ToVec3a((ToVec2a(PA) - H * ToVec2a(Pendiculara(Direction))));
	result.push_back(S1);
	result.push_back(S2);
	return result;
}

 bool GetSegmentSegmentIntersectionsa(
	Vec2 lineSegment1Start,
	Vec2 lineSegment1End,
	Vec2 lineSegment2Start,
	Vec2 lineSegment2End,
	Vec2& intersectpoint)
{
	float deltaACy = lineSegment1Start.y - lineSegment2Start.y;
	float deltaDCx = lineSegment2End.x - lineSegment2Start.x;
	float deltaACx = lineSegment1Start.x - lineSegment2Start.x;
	float deltaDCy = lineSegment2End.y - lineSegment2Start.y;
	float deltaBAx = lineSegment1End.x - lineSegment1Start.x;
	float deltaBAy = lineSegment1End.y - lineSegment1Start.y;

	float denominator = deltaBAx * deltaDCy - deltaBAy * deltaDCx;
	float numerator = deltaACy * deltaDCx - deltaACx * deltaDCy;

	if (abs(denominator) < std::numeric_limits<float>::epsilon())
	{
		if (abs(numerator) < std::numeric_limits<float>::epsilon())
		{
			// collinear. Potentially infinite intersection points.
			// Check and return one of them.
			if (lineSegment1Start.x >= lineSegment2Start.x && lineSegment1Start.x <= lineSegment2End.x)
			{
				intersectpoint = lineSegment1Start;
				return true;
			}
			if (lineSegment2Start.x >= lineSegment1Start.x && lineSegment2Start.x <= lineSegment1End.x)
			{
				intersectpoint = lineSegment2Start;
				return true;
			}
			return false;
		}
		// parallel
		return false;
	}

	float r = numerator / denominator;
	if (r < 0 || r > 1)
	{
		return false;
	}

	float s = (deltaACy * deltaBAx - deltaACx * deltaBAy) / denominator;
	if (s < 0 || s > 1)
	{
		return false;
	}
	intersectpoint.x = lineSegment1Start.x + r * deltaBAx;
	intersectpoint.y = lineSegment1Start.y + r * deltaBAy;
	return true;
}
 bool GetSegmentSegmentIntersectionsa(
	Vec3 lineSegment1Start,
	Vec3 lineSegment1End,
	Vec3 lineSegment2Start,
	Vec3 lineSegment2End)
{
	Vec2 out;
	return GetSegmentSegmentIntersectionsa(ToVec2a(lineSegment1Start), ToVec2a(lineSegment1End), ToVec2a(lineSegment2Start), ToVec2a(lineSegment2End), out);
}
