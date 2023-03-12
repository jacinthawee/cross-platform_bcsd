
stack_st_PKCS12_SAFEBAG * PKCS12_unpack_p7encdata(PKCS7 *p7,char *pass,int passlen)

{
  PKCS7_ENC_CONTENT *pPVar1;
  int iVar2;
  stack_st_PKCS12_SAFEBAG *psVar3;
  
  iVar2 = OBJ_obj2nid(p7->type);
  psVar3 = (stack_st_PKCS12_SAFEBAG *)0x0;
  if (iVar2 == 0x1a) {
    pPVar1 = ((p7->d).encrypted)->enc_data;
    psVar3 = (stack_st_PKCS12_SAFEBAG *)
             PKCS12_item_decrypt_d2i
                       (pPVar1->algorithm,(ASN1_ITEM *)PKCS12_SAFEBAGS_it,pass,passlen,
                        pPVar1->enc_data,1);
  }
  return psVar3;
}

