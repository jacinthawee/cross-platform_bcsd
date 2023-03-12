
OCSP_BASICRESP * OCSP_response_get1_basic(OCSP_RESPONSE *resp)

{
  int iVar1;
  OCSP_BASICRESP *pOVar2;
  OCSP_RESPBYTES *pOVar3;
  
  pOVar3 = resp->responseBytes;
  if (pOVar3 == (OCSP_RESPBYTES *)0x0) {
    ERR_put_error(0x27,0x6f,0x6c,"ocsp_cl.c",0xd1);
  }
  else {
    iVar1 = OBJ_obj2nid(pOVar3->responseType);
    if (iVar1 == 0x16d) {
      pOVar2 = (OCSP_BASICRESP *)ASN1_item_unpack(pOVar3->response,(ASN1_ITEM *)OCSP_BASICRESP_it);
      return pOVar2;
    }
    ERR_put_error(0x27,0x6f,0x68,"ocsp_cl.c",0xd5);
  }
  return (OCSP_BASICRESP *)0x0;
}

