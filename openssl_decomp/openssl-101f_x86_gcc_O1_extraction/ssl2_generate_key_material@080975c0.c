
undefined4 ssl2_generate_key_material(int param_1)

{
  uchar *puVar1;
  uint *puVar2;
  uchar *puVar3;
  uchar *md;
  EVP_MD *md_00;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uchar *puVar7;
  int in_GS_OFFSET;
  int iVar8;
  char local_39;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_39 = '0';
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  md_00 = EVP_md5();
  EVP_MD_CTX_init(&local_38);
  if (*(uint *)(*(int *)(param_1 + 0xc0) + 0x10) < 0x31) {
    iVar8 = *(int *)(param_1 + 0x54);
    iVar4 = EVP_MD_size(md_00);
    if (iVar4 < 0) {
      uVar5 = 0;
      goto LAB_08097750;
    }
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x9c) == 0) {
LAB_08097768:
      EVP_MD_CTX_cleanup(&local_38);
      uVar5 = 1;
      goto LAB_08097750;
    }
    puVar1 = (uchar *)(iVar8 + 0xa0);
    puVar3 = (uchar *)((iVar8 - *(int *)(param_1 + 0x54)) + iVar4);
    md = puVar1;
    while ((int)puVar3 < 0x31) {
      EVP_DigestInit_ex(&local_38,md_00,(ENGINE *)0x0);
      iVar8 = *(int *)(param_1 + 0xc0);
      uVar6 = *(uint *)(iVar8 + 0x10);
      if (0x2f < uVar6) {
        OpenSSLDie("s2_lib.c",0x1e9,
                   "s->session->master_key_length >= 0 && s->session->master_key_length < (int)sizeof(s->session->master_key)"
                  );
        iVar8 = *(int *)(param_1 + 0xc0);
        uVar6 = *(size_t *)(iVar8 + 0x10);
      }
      EVP_DigestUpdate(&local_38,(void *)(iVar8 + 0x14),uVar6);
      EVP_DigestUpdate(&local_38,&local_39,1);
      local_39 = local_39 + '\x01';
      EVP_DigestUpdate(&local_38,(void *)(*(int *)(param_1 + 0x54) + 0x68),
                       *(size_t *)(*(int *)(param_1 + 0x54) + 100));
      EVP_DigestUpdate(&local_38,(void *)(*(int *)(param_1 + 0x54) + 0x8c),
                       *(size_t *)(*(int *)(param_1 + 0x54) + 0x88));
      puVar7 = md + iVar4;
      EVP_DigestFinal_ex(&local_38,md,(uint *)0x0);
      uVar6 = (int)puVar7 - (int)puVar1;
      puVar2 = (uint *)(*(int *)(param_1 + 0x54) + 0x9c);
      if (*puVar2 < uVar6 || *puVar2 == uVar6) goto LAB_08097768;
      md = puVar7;
      puVar3 = puVar7 + iVar4 + (-0xa0 - *(int *)(param_1 + 0x54));
    }
    iVar8 = 0x1e1;
  }
  else {
    iVar8 = 0x1d5;
  }
  ERR_put_error(0x14,0xf1,0x44,"s2_lib.c",iVar8);
  uVar5 = 0;
LAB_08097750:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

