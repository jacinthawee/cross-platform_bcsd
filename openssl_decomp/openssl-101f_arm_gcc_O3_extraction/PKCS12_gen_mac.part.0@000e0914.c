
void PKCS12_gen_mac_part_0(int param_1,char *param_2,int param_3,uchar *param_4,uint *param_5)

{
  int iVar1;
  char *name;
  EVP_MD *md;
  EVP_MD *pEVar2;
  int iVar3;
  size_t *psVar4;
  undefined4 *puVar5;
  uchar *salt;
  long iter;
  uchar auStack_13c [64];
  HMAC_CTX HStack_fc;
  int local_2c;
  
  puVar5 = *(undefined4 **)(param_1 + 4);
  local_2c = __TMC_END__;
  iter = 1;
  salt = (uchar *)((int *)puVar5[1])[2];
  iVar3 = *(int *)puVar5[1];
  if ((ASN1_INTEGER *)puVar5[2] != (ASN1_INTEGER *)0x0) {
    iter = ASN1_INTEGER_get((ASN1_INTEGER *)puVar5[2]);
    puVar5 = *(undefined4 **)(param_1 + 4);
  }
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)*puVar5);
  name = OBJ_nid2sn(iVar1);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x23,0x6b,0x76,"p12_mutl.c",0x58);
  }
  else {
    iVar1 = EVP_MD_size(md);
    if (iVar1 < 0) {
      md = (EVP_MD *)0x0;
    }
    else {
      pEVar2 = (EVP_MD *)PKCS12_key_gen_asc(param_2,param_3,salt,iVar3,3,iter,iVar1,auStack_13c,md);
      if (pEVar2 == (EVP_MD *)0x0) {
        ERR_put_error(0x23,0x6b,0x6b,"p12_mutl.c",0x60);
        md = pEVar2;
      }
      else {
        HMAC_CTX_init(&HStack_fc);
        iVar3 = HMAC_Init_ex(&HStack_fc,auStack_13c,iVar1,md,(ENGINE *)0x0);
        if (((iVar3 == 0) ||
            (psVar4 = *(size_t **)(*(int *)(param_1 + 8) + 0x14),
            iVar3 = HMAC_Update(&HStack_fc,(uchar *)psVar4[2],*psVar4), iVar3 == 0)) ||
           (iVar3 = HMAC_Final(&HStack_fc,param_4,param_5), iVar3 == 0)) {
          HMAC_CTX_cleanup(&HStack_fc);
          md = (EVP_MD *)0x0;
        }
        else {
          HMAC_CTX_cleanup(&HStack_fc);
          md = (EVP_MD *)0x1;
        }
      }
    }
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(md);
  }
  return;
}

