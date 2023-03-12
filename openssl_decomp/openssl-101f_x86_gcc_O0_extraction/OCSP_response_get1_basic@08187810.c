
OCSP_BASICRESP * OCSP_response_get1_basic(OCSP_RESPONSE *resp)

{
  OCSP_RESPBYTES *pOVar1;
  int iVar2;
  OCSP_BASICRESP *pOVar3;
  int line;
  
  pOVar1 = resp->responseBytes;
  if (pOVar1 == (OCSP_RESPBYTES *)0x0) {
    line = 0xcb;
    iVar2 = 0x6c;
  }
  else {
    iVar2 = OBJ_obj2nid(pOVar1->responseType);
    if (iVar2 == 0x16d) {
      pOVar3 = (OCSP_BASICRESP *)ASN1_item_unpack(pOVar1->response,(ASN1_ITEM *)OCSP_BASICRESP_it);
      return pOVar3;
    }
    line = 0xd0;
    iVar2 = 0x68;
  }
  ERR_put_error(0x27,0x6f,iVar2,"ocsp_cl.c",line);
  return (OCSP_BASICRESP *)0x0;
}

