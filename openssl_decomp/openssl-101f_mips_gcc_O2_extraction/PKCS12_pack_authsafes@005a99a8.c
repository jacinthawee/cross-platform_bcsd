
int PKCS12_pack_authsafes(PKCS12 *p12,stack_st_PKCS7 *safes)

{
  int iVar1;
  undefined4 in_a3;
  
  iVar1 = (*(code *)PTR_ASN1_item_pack_006a9f14)
                    (safes,PTR_PKCS12_AUTHSAFES_it_006aa304,&p12->authsafes->d,in_a3,&_gp);
  return (uint)(iVar1 != 0);
}
