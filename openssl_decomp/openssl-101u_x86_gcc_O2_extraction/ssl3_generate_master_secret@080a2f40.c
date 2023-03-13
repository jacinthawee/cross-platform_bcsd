
int ssl3_generate_master_secret(int param_1,uchar *param_2,void *param_3,size_t param_4)

{
  char *__s;
  int iVar1;
  size_t cnt;
  undefined1 *puVar2;
  int in_GS_OFFSET;
  uchar *local_88;
  int local_84;
  size_t local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  puVar2 = salt_15952;
  local_88 = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_78);
  local_84 = 0;
  do {
    iVar1 = EVP_DigestInit_ex(&local_78,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0)
    ;
    if (iVar1 < 1) {
LAB_080a3110:
      ERR_put_error(0x14,0x184,0x44,"s3_enc.c",0x356);
      local_84 = 0;
      break;
    }
    __s = *(char **)puVar2;
    cnt = strlen(__s);
    iVar1 = EVP_DigestUpdate(&local_78,__s,cnt);
    if (iVar1 < 1) goto LAB_080a3110;
    iVar1 = EVP_DigestUpdate(&local_78,param_3,param_4);
    if (iVar1 < 1) goto LAB_080a3110;
    iVar1 = EVP_DigestUpdate(&local_78,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
    if (iVar1 < 1) goto LAB_080a3110;
    iVar1 = EVP_DigestUpdate(&local_78,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
    if (iVar1 < 1) goto LAB_080a3110;
    iVar1 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
    if (iVar1 < 1) goto LAB_080a3110;
    iVar1 = EVP_DigestInit_ex(&local_78,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),(ENGINE *)0x0)
    ;
    if (iVar1 < 1) goto LAB_080a3110;
    iVar1 = EVP_DigestUpdate(&local_78,param_3,param_4);
    if (iVar1 < 1) goto LAB_080a3110;
    iVar1 = EVP_DigestUpdate(&local_78,local_60,local_7c);
    if (iVar1 < 1) goto LAB_080a3110;
    iVar1 = EVP_DigestFinal_ex(&local_78,local_88,&local_7c);
    if (iVar1 < 1) goto LAB_080a3110;
    puVar2 = (undefined1 *)((int)puVar2 + 4);
    local_88 = local_88 + local_7c;
    local_84 = local_84 + local_7c;
  } while (puVar2 != "s3_pkt.c");
  EVP_MD_CTX_cleanup(&local_78);
  OPENSSL_cleanse(local_60,0x40);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_84;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

