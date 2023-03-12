
OCSP_RESPONSE * OCSP_response_create(int status,OCSP_BASICRESP *bs)

{
  OCSP_RESPONSE *a;
  int iVar1;
  OCSP_RESPBYTES *pOVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_STRING *pAVar4;
  
  a = OCSP_RESPONSE_new();
  if (a != (OCSP_RESPONSE *)0x0) {
    iVar1 = ASN1_ENUMERATED_set(a->responseStatus,status);
    if (iVar1 != 0) {
      if (bs == (OCSP_BASICRESP *)0x0) {
        return a;
      }
      pOVar2 = OCSP_RESPBYTES_new();
      a->responseBytes = pOVar2;
      if (pOVar2 != (OCSP_RESPBYTES *)0x0) {
        pAVar3 = OBJ_nid2obj(0x16d);
        pOVar2->responseType = pAVar3;
        pAVar4 = ASN1_item_pack(bs,(ASN1_ITEM *)OCSP_BASICRESP_it,&a->responseBytes->response);
        if (pAVar4 != (ASN1_STRING *)0x0) {
          return a;
        }
      }
    }
    OCSP_RESPONSE_free(a);
  }
  return (OCSP_RESPONSE *)0x0;
}

