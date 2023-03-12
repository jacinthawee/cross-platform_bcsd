
undefined4 ssl2_generate_key_material(int param_1)

{
  EVP_MD *md;
  int iVar1;
  size_t cnt;
  int iVar2;
  uint uVar3;
  uchar *md_00;
  uchar *puVar4;
  char local_40 [8];
  EVP_MD_CTX EStack_38;
  
  local_40[0] = '0';
  md = EVP_md5();
  EVP_MD_CTX_init(&EStack_38);
  iVar2 = *(int *)(param_1 + 0x54);
  if (*(uint *)(*(int *)(param_1 + 0xc0) + 0x10) < 0x31) {
    iVar1 = EVP_MD_size(md);
    if (iVar1 < 0) {
      return 0;
    }
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x9c) == 0) {
LAB_00046cb6:
      EVP_MD_CTX_cleanup(&EStack_38);
      return 1;
    }
    puVar4 = (uchar *)(iVar2 + 0xa0);
    if ((iVar2 - *(int *)(param_1 + 0x54)) + iVar1 < 0x31) {
      uVar3 = 0;
      md_00 = puVar4;
      do {
        EVP_DigestInit_ex(&EStack_38,md,(ENGINE *)0x0);
        iVar2 = *(int *)(param_1 + 0xc0);
        cnt = *(uint *)(iVar2 + 0x10);
        if (0x2f < cnt) {
          OpenSSLDie("s2_lib.c",0x1e9,
                     "s->session->master_key_length >= 0 && s->session->master_key_length < (int)sizeof(s->session->master_key)"
                    );
          iVar2 = *(int *)(param_1 + 0xc0);
          cnt = *(size_t *)(iVar2 + 0x10);
        }
        EVP_DigestUpdate(&EStack_38,(void *)(iVar2 + 0x14),cnt);
        EVP_DigestUpdate(&EStack_38,local_40,1);
        uVar3 = uVar3 + iVar1;
        local_40[0] = local_40[0] + '\x01';
        EVP_DigestUpdate(&EStack_38,(void *)(*(int *)(param_1 + 0x54) + 0x68),
                         *(size_t *)(*(int *)(param_1 + 0x54) + 100));
        EVP_DigestUpdate(&EStack_38,(void *)(*(int *)(param_1 + 0x54) + 0x8c),
                         *(size_t *)(*(int *)(param_1 + 0x54) + 0x88));
        EVP_DigestFinal_ex(&EStack_38,md_00,(uint *)0x0);
        md_00 = puVar4 + uVar3;
        if (*(uint *)(*(int *)(param_1 + 0x54) + 0x9c) <= uVar3) goto LAB_00046cb6;
      } while ((int)(md_00 + (iVar1 - (*(int *)(param_1 + 0x54) + 0xa0))) < 0x31);
    }
    iVar2 = 0x1e1;
  }
  else {
    iVar2 = 0x1d5;
  }
  ERR_put_error(0x14,0xf1,0x44,"s2_lib.c",iVar2);
  return 0;
}

