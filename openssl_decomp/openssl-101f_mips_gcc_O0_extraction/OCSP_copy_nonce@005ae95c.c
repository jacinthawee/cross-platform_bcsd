
int OCSP_copy_nonce(OCSP_BASICRESP *resp,OCSP_REQUEST *req)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_X509v3_get_ext_by_NID_006aa064)
                    (req->tbsRequest->requestExtensions,0x16e,0xffffffff);
  if (iVar1 < 0) {
    return 2;
  }
  uVar2 = (*(code *)PTR_X509v3_get_ext_006aa070)(req->tbsRequest->requestExtensions,iVar1);
  iVar1 = (*(code *)PTR_X509v3_add_ext_006aa080)
                    (&resp->tbsResponseData->responseExtensions,uVar2,0xffffffff);
  return (uint)(iVar1 != 0);
}

