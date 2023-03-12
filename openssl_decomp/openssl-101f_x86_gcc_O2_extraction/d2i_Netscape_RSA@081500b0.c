
RSA * d2i_Netscape_RSA(RSA **a,uchar **pp,long length,cb *cb)

{
  int **val;
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  RSA *pRVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  bool bVar6;
  byte bVar7;
  uchar *local_24;
  int local_20;
  
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *pp;
  val = (int **)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_24,length,
                              (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  if (val == (int **)0x0) {
    ERR_put_error(0xd,200,0x6f,"n_pkey.c",0x101);
    pRVar4 = (RSA *)0x0;
  }
  else {
    bVar6 = **val == 0xb;
    if (bVar6) {
      iVar2 = 0xb;
      pcVar3 = "private-key";
      pcVar5 = (char *)(*val)[2];
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + (uint)bVar7 * -2 + 1;
        pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
      } while (bVar6);
      if (bVar6) {
        iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)*val[1]);
        if (iVar2 == 5) {
          pcVar1 = EVP_read_pw_string;
          if (cb != (cb *)0x0) {
            pcVar1 = cb;
          }
          pRVar4 = (RSA *)d2i_RSA_NET_2_isra_0(pcVar1,0);
          if (pRVar4 != (RSA *)0x0) {
            *pp = local_24;
          }
        }
        else {
          pRVar4 = (RSA *)0x0;
          ERR_put_error(0xd,200,0xa6,"n_pkey.c",0x10e);
        }
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        goto LAB_0815016d;
      }
    }
    ERR_put_error(0xd,200,0x92,"n_pkey.c",0x108);
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
    pRVar4 = (RSA *)0x0;
  }
LAB_0815016d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pRVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

