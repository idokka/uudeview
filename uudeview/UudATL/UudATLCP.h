#ifndef _UUDATLCP_H_
#define _UUDATLCP_H_

#pragma warning(disable : 4800)

template <class T>
class CProxy_IUUEngineEvents : public IConnectionPointImpl<T, &DIID__IUUEngineEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:
	VOID Fire_Message(BSTR Message, SHORT Level)
	{
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = Message;
				pvars[0] = Level;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}

	VOID Fire_Progress(LONG CurrentAction, BSTR CurrentFile, SHORT PartNo, SHORT TotalParts, LONG CurrentFileSize, SHORT Percent, BOOL * Cancel)
	{
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[7];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[6] = CurrentAction;
				pvars[5] = CurrentFile;
				pvars[4] = PartNo;
				pvars[3] = TotalParts;
				pvars[2] = CurrentFileSize;
				pvars[1] = Percent;
				pvars[0] = Cancel;
				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}


};

#pragma warning(default : 4800)
#endif