
int __regparm3
PKCS12_gen_mac_part_0(int param_1_00,char *param_2_00,int param_3,uchar *param_1,uint *param_2)

{
  uchar *salt;
  size_t *psVar1;
  undefined4 *puVar2;
  int iVar3;
  char *name;
  EVP_MD *md;
  int n;
  int iVar4;
  long iter;
  int in_GS_OFFSET;
  HMAC_CTX local_130;
  uchar local_60 [64];
  int local_20;
  
  iter = 1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar2 = *(undefined4 **)(param_1_00 + 4);
  salt = (uchar *)((int *)puVar2[1])[2];
  iVar4 = *(int *)puVar2[1];
  if ((ASN1_INTEGER *)puVar2[2] != (ASN1_INTEGER *)0x0) {
    iter = ASN1_INTEGER_get((ASN1_INTEGER *)puVar2[2]);
    puVar2 = *(undefined4 **)(param_1_00 + 4);
  }
  iVar3 = OBJ_obj2nid(**(ASN1_OBJECT ***)*puVar2);
  name = OBJ_nid2sn(iVar3);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x23,0x6b,0x76,"p12_mutl.c",0x5a);
    iVar3 = 0;
  }
  else {
    n = EVP_MD_size(md);
    iVar3 = 0;
    if (-1 < n) {
      iVar3 = PKCS12_key_gen_asc(param_2_00,param_3,salt,iVar4,3,iter,n,local_60,md);
      if (iVar3 == 0) {
        ERR_put_error(0x23,0x6b,0x6b,"p12_mutl.c",0x62);
      }
      else {
        HMAC_CTX_init(&local_130);
        iVar4 = HMAC_Init_ex(&local_130,local_60,n,md,(ENGINE *)0x0);
        if (iVar4 != 0) {
          psVar1 = *(size_t **)(*(int *)(param_1_00 + 8) + 0x14);
          iVar4 = HMAC_Update(&local_130,(uchar *)psVar1[2],*psVar1);
          if (iVar4 != 0) {
            iVar4 = HMAC_Final(&local_130,param_1,param_2);
            if (iVar4 != 0) {
              HMAC_CTX_cleanup(&local_130);
              iVar3 = 1;
              goto LAB_08182b8c;
            }
          }
        }
        HMAC_CTX_cleanup(&local_130);
        iVar3 = 0;
      }
    }
  }
LAB_08182b8c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

