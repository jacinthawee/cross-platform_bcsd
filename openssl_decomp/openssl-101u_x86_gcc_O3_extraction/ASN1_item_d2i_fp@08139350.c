
/* WARNING: Removing unreachable block (ram,0x081393d4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * ASN1_item_d2i_fp(ASN1_ITEM *it,FILE *in,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int len;
  ASN1_VALUE *pAVar1;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x85);
    pAVar1 = (ASN1_VALUE *)0x0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,in);
    len = asn1_d2i_read_bio_constprop_0();
    if (len < 0) {
      pAVar1 = (ASN1_VALUE *)0x0;
    }
    else {
      local_24 = _DAT_00000004;
      pAVar1 = ASN1_item_d2i((ASN1_VALUE **)x,&local_24,len,it);
    }
    BIO_free(bp);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pAVar1;
}

