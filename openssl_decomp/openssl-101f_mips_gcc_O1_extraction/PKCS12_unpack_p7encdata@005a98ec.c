
stack_st_PKCS12_SAFEBAG * PKCS12_unpack_p7encdata(PKCS7 *p7,char *pass,int passlen)

{
  int iVar1;
  PKCS7_ENC_CONTENT *pPVar2;
  stack_st_PKCS12_SAFEBAG *psVar3;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  if (iVar1 == 0x1a) {
    pPVar2 = ((p7->d).encrypted)->enc_data;
    psVar3 = (stack_st_PKCS12_SAFEBAG *)
             PKCS12_item_decrypt_d2i
                       (pPVar2->algorithm,(ASN1_ITEM *)PTR_PKCS12_SAFEBAGS_it_006aa2ec,pass,passlen,
                        pPVar2->enc_data,1);
    return psVar3;
  }
  return (stack_st_PKCS12_SAFEBAG *)0x0;
}

