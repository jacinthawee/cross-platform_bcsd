
int PKCS12_gen_mac(PKCS12 *p12,char *pass,int passlen,uchar *mac,uint *maclen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p12->authsafes->type);
  if (iVar1 == 0x15) {
    iVar1 = PKCS12_gen_mac_part_0(p12,pass,passlen,mac);
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6b,0x79,"p12_mutl.c",0x4f);
  return 0;
}

