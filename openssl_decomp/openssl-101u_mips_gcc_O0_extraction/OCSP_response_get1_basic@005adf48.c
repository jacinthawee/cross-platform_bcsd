
OCSP_BASICRESP * OCSP_response_get1_basic(OCSP_RESPONSE *resp)

{
  int iVar1;
  OCSP_BASICRESP *pOVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  OCSP_RESPBYTES *pOVar5;
  
  pOVar5 = resp->responseBytes;
  if (pOVar5 == (OCSP_RESPBYTES *)0x0) {
    uVar4 = 0x6c;
    uVar3 = 0xd1;
  }
  else {
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pOVar5->responseType);
    if (iVar1 == 0x16d) {
                    /* WARNING: Could not recover jumptable at 0x005adf94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pOVar2 = (OCSP_BASICRESP *)
               (*(code *)PTR_ASN1_item_unpack_006a91d8)
                         (pOVar5->response,PTR_OCSP_BASICRESP_it_006a928c);
      return pOVar2;
    }
    uVar4 = 0x68;
    uVar3 = 0xd5;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x6f,uVar4,"ocsp_cl.c",uVar3);
  return (OCSP_BASICRESP *)0x0;
}

