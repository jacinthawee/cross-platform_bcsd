
int OCSP_check_nonce(OCSP_REQUEST *req,OCSP_BASICRESP *bs)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (*(code *)PTR_X509v3_get_ext_by_NID_006aa064)
                    (req->tbsRequest->requestExtensions,0x16e,0xffffffff);
  iVar2 = (*(code *)PTR_X509v3_get_ext_by_NID_006aa064)
                    (bs->tbsResponseData->responseExtensions,0x16e,0xffffffff);
  if (-1 < iVar1) {
    if (iVar2 < 0) {
      uVar3 = 0xffffffff;
    }
    else {
      iVar1 = (*(code *)PTR_X509v3_get_ext_006aa070)(req->tbsRequest->requestExtensions,iVar1);
      iVar2 = (*(code *)PTR_X509v3_get_ext_006aa070)(bs->tbsResponseData->responseExtensions,iVar2);
      iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)
                        (*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar2 + 8));
      uVar3 = (uint)(iVar1 == 0);
    }
    return uVar3;
  }
  iVar1 = 3;
  if (iVar2 < 0) {
    iVar1 = 2;
  }
  return iVar1;
}

