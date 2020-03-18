#pragma once

#include "PointVisitor.h"

class TiXmlNode;

namespace tg
{
	namespace io
	{
		class PointVisitor;

		class PointsToOSG
		{
		public:
			///////////////////////////////////////
			// constructors and destructor

			TG_EXPORT PointsToOSG(std::shared_ptr<PointVisitor> i_oPointVisitor);

			TG_EXPORT ~PointsToOSG();

			///////////////////////////////////////
			// public member functions

			TG_EXPORT int Write(const char* i_cFilePath);

		private:
			///////////////////////////////////////
			// private member functions

			bool LoadPointsForOneTile(std::shared_ptr<PointVisitor> i_oPointVisitor,
				std::vector<tg::PointXYZINormalClassT<IntentType, IntenDim>>& i_lstPoints);

			int ExportOffset(const char* i_cFilePath);
			int AddLeafNode(TiXmlNode* pElmParent, const char* pszNode, const char* pszText);
			int AddLeafNode(TiXmlNode* pElmParent, const char* pszNode, double doubText);
			int AddLeafNode(TiXmlNode* pElmParent, const char* pszNode, int intText);

			///////////////////////////////////////
			// private variables

			size_t m_nTileSize;
			size_t m_nProcessedPoints;
			unsigned int m_nMaxTreeDepth;
			unsigned int m_nMaxPointNumPerOneNode;
			double m_dLodRatio;
			float m_fPointSize;

			std::shared_ptr<PointVisitor> m_oPointVisitor;
		};

	};
};