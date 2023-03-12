
int PKCS12_verify_mac(PKCS12 *p12,char *pass,int passlen)

{
  ASN1_OCTET_STRING *pAVar1;
  size_t __n;
  int iVar2;
  uint uVar3;
  int in_GS_OFFSET;
  size_t local_54;
  undefined local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (p12->mac == (PKCS12_MAC_DATA *)0x0) {
    ERR_put_error(0x23,0x7e,0x6c,"p12_mutl.c",0x76);
    uVar3 = 0;
  }
  else {
    iVar2 = OBJ_obj2nid(p12->authsafes->type);
    if (iVar2 == 0x15) {
      iVar2 = PKCS12_gen_mac_part_0(local_50,&local_54);
      if (iVar2 != 0) {
        pAVar1 = p12->mac->dinfo->digest;
        uVar3 = 0;
        __n = pAVar1->length;
        if (__n == local_54) {
          iVar2 = memcmp(local_50,pAVar1->data,__n);
          uVar3 = (uint)(iVar2 == 0);
        }
        goto LAB_0818486e;
      }
    }
    else {
      ERR_put_error(0x23,0x6b,0x79,"p12_mutl.c",0x4e);
    }
    ERR_put_error(0x23,0x7e,0x6d,"p12_mutl.c",0x7a);
    uVar3 = 0;
  }
LAB_0818486e:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

