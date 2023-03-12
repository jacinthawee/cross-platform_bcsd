
uint n_ssl3_mac(int param_1,uchar *param_2,int param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  char cVar7;
  EVP_MD *md;
  uint uVar8;
  size_t __n;
  ulong uVar9;
  int iVar10;
  undefined4 *d;
  uint *puVar11;
  int in_GS_OFFSET;
  EVP_MD_CTX *local_b4;
  void *local_b0;
  undefined local_8d;
  uint local_8c;
  uint local_88;
  EVP_MD_CTX local_84;
  undefined4 local_6b [2];
  undefined auStack_63 [67];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar10 = *(int *)(param_1 + 0x58);
  if (param_3 == 0) {
    local_b0 = (void *)(iVar10 + 0x14);
    puVar11 = (uint *)(iVar10 + 0x10c);
    d = (undefined4 *)(iVar10 + 8);
    local_b4 = *(EVP_MD_CTX **)(param_1 + 0x84);
  }
  else {
    local_b0 = (void *)(iVar10 + 0x60);
    puVar11 = (uint *)(iVar10 + 0x130);
    d = (undefined4 *)(iVar10 + 0x54);
    local_b4 = *(EVP_MD_CTX **)(param_1 + 0x90);
  }
  md = EVP_MD_CTX_md(local_b4);
  uVar8 = EVP_MD_size(md);
  if ((int)uVar8 < 0) {
    uVar8 = 0xffffffff;
  }
  else {
    uVar3 = *puVar11;
    __n = (int)(0x30 / (ulonglong)uVar8) * uVar8;
    uVar4 = puVar11[1];
    *puVar11 = uVar3 & 0xff;
    local_8c = uVar8;
    if (((param_3 == 0) &&
        (uVar9 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)), (uVar9 & 0xf0007) == 2)
        ) && (cVar7 = ssl3_cbc_record_digest_supported(local_b4), uVar6 = local_8c, cVar7 != '\0'))
    {
      __memcpy_chk(local_6b,local_b0,local_8c,0x4b);
      memcpy((void *)((int)local_6b + uVar6),ssl3_pad_1,__n);
      iVar10 = __n + uVar6;
      uVar5 = d[1];
      *(undefined4 *)((int)local_6b + iVar10) = *d;
      *(undefined4 *)((int)local_6b + iVar10 + 4) = uVar5;
      auStack_63[iVar10] = (char)*puVar11;
      auStack_63[iVar10 + 1] = (char)(puVar11[1] >> 8);
      auStack_63[iVar10 + 2] = (char)puVar11[1];
      ssl3_cbc_digest_record
                (local_b4,param_2,&local_8c,local_6b,puVar11[4],uVar6 + puVar11[1],
                 uVar8 + (uVar3 >> 8) + uVar4,local_b0,uVar6,1);
    }
    else {
      EVP_MD_CTX_init(&local_84);
      EVP_MD_CTX_copy_ex(&local_84,local_b4);
      EVP_DigestUpdate(&local_84,local_b0,local_8c);
      EVP_DigestUpdate(&local_84,ssl3_pad_1,__n);
      EVP_DigestUpdate(&local_84,d,8);
      local_8d = (undefined)*puVar11;
      EVP_DigestUpdate(&local_84,&local_8d,1);
      *param_2 = (uchar)(puVar11[1] >> 8);
      param_2[1] = (uchar)puVar11[1];
      EVP_DigestUpdate(&local_84,param_2,2);
      EVP_DigestUpdate(&local_84,(void *)puVar11[4],puVar11[1]);
      EVP_DigestFinal_ex(&local_84,param_2,(uint *)0x0);
      EVP_MD_CTX_copy_ex(&local_84,local_b4);
      EVP_DigestUpdate(&local_84,local_b0,local_8c);
      EVP_DigestUpdate(&local_84,
                       "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"
                       ,__n);
      EVP_DigestUpdate(&local_84,param_2,local_8c);
      EVP_DigestFinal_ex(&local_84,param_2,&local_88);
      local_8c = local_88;
      EVP_MD_CTX_cleanup(&local_84);
    }
    pcVar1 = (char *)((int)d + 7);
    *pcVar1 = *pcVar1 + '\x01';
    uVar8 = local_8c;
    if (*pcVar1 == '\0') {
      pcVar1 = (char *)((int)d + 6);
      *pcVar1 = *pcVar1 + '\x01';
      if (*pcVar1 == '\0') {
        pcVar1 = (char *)((int)d + 5);
        *pcVar1 = *pcVar1 + '\x01';
        if (*pcVar1 == '\0') {
          puVar2 = d + 1;
          *(char *)puVar2 = *(char *)puVar2 + '\x01';
          if (*(char *)puVar2 == '\0') {
            pcVar1 = (char *)((int)d + 3);
            *pcVar1 = *pcVar1 + '\x01';
            if (*pcVar1 == '\0') {
              pcVar1 = (char *)((int)d + 2);
              *pcVar1 = *pcVar1 + '\x01';
              if (*pcVar1 == '\0') {
                pcVar1 = (char *)((int)d + 1);
                *pcVar1 = *pcVar1 + '\x01';
                if (*pcVar1 == '\0') {
                  *(char *)d = *(char *)d + '\x01';
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}

