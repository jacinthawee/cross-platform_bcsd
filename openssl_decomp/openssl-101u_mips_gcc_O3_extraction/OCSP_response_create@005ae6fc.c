
OCSP_RESPONSE * OCSP_response_create(int status,OCSP_BASICRESP *bs)

{
  OCSP_RESPONSE *a;
  int iVar1;
  OCSP_RESPBYTES *pOVar2;
  ASN1_OBJECT *pAVar3;
  OCSP_RESPBYTES *pOVar4;
  
  a = OCSP_RESPONSE_new();
  if (a == (OCSP_RESPONSE *)0x0) {
    return (OCSP_RESPONSE *)0x0;
  }
  iVar1 = (*(code *)PTR_ASN1_ENUMERATED_set_006a7048)(a->responseStatus,status);
  if (iVar1 != 0) {
    if (bs == (OCSP_BASICRESP *)0x0) {
      return a;
    }
    pOVar2 = OCSP_RESPBYTES_new();
    a->responseBytes = pOVar2;
    if (pOVar2 != (OCSP_RESPBYTES *)0x0) {
      pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0x16d);
      pOVar4 = a->responseBytes;
      pOVar2->responseType = pAVar3;
      iVar1 = (*(code *)PTR_ASN1_item_pack_006a8df4)
                        (bs,PTR_OCSP_BASICRESP_it_006a928c,&pOVar4->response);
      if (iVar1 != 0) {
        return a;
      }
    }
  }
  OCSP_RESPONSE_free(a);
  return (OCSP_RESPONSE *)0x0;
}

