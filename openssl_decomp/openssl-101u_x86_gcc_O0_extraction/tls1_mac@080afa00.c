
size_t tls1_mac(int *param_1,uchar *param_2,int param_3)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  EVP_MD *md;
  ulong uVar7;
  int iVar8;
  size_t sVar9;
  undefined4 *puVar10;
  EVP_MD_CTX *ctx;
  EVP_MD_CTX *out;
  uint *puVar11;
  int in_GS_OFFSET;
  uint local_70;
  undefined local_6c;
  size_t local_54;
  EVP_MD_CTX local_50;
  undefined local_35;
  undefined uStack_34;
  undefined2 uStack_33;
  undefined2 uStack_31;
  undefined2 uStack_2f;
  undefined4 local_2d;
  undefined4 local_29;
  undefined local_25;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 == 0) {
    local_70 = param_1[0x1f] & 1;
    ctx = (EVP_MD_CTX *)param_1[0x21];
    puVar11 = (uint *)(param_1[0x16] + 0x10c);
    puVar10 = (undefined4 *)(param_1[0x16] + 8);
  }
  else {
    ctx = (EVP_MD_CTX *)param_1[0x24];
    local_70 = param_1[0x1f] & 2;
    puVar11 = (uint *)(param_1[0x16] + 0x130);
    puVar10 = (undefined4 *)(param_1[0x16] + 0x54);
  }
  md = EVP_MD_CTX_md(ctx);
  local_54 = EVP_MD_size(md);
  if ((int)local_54 < 0) {
    OpenSSLDie("t1_enc.c",0x3f4,"t >= 0");
  }
  out = ctx;
  if (local_70 == 0) {
    out = &local_50;
    iVar8 = EVP_MD_CTX_copy(out,ctx);
    if (iVar8 != 0) goto LAB_080afa7c;
  }
  else {
LAB_080afa7c:
    sVar9 = local_54;
    iVar8 = *param_1;
    if ((iVar8 == 0xfeff) || (iVar8 == 0x100)) {
      if (param_3 == 0) {
        uVar3 = *(undefined2 *)(param_1[0x17] + 0x208);
        local_35 = (undefined)((ushort)uVar3 >> 8);
      }
      else {
        uVar3 = *(undefined2 *)(param_1[0x17] + 0x20a);
        local_35 = (undefined)((ushort)uVar3 >> 8);
      }
      uStack_34 = (undefined)uVar3;
      uStack_33 = (undefined2)*(undefined4 *)((int)puVar10 + 2);
      uStack_31 = (undefined2)((uint)*(undefined4 *)((int)puVar10 + 2) >> 0x10);
      uStack_2f = *(undefined2 *)((int)puVar10 + 6);
      local_2d = CONCAT22(uStack_33,CONCAT11(uStack_34,local_35));
      local_29 = CONCAT22(uStack_2f,uStack_31);
    }
    else {
      local_2d = *puVar10;
      local_29 = puVar10[1];
    }
    uVar4 = puVar11[1];
    uVar5 = *puVar11;
    *puVar11 = uVar5 & 0xff;
    local_6c = (undefined)uVar5;
    local_23 = (undefined)iVar8;
    local_21 = (undefined)uVar4;
    local_25 = local_6c;
    local_24 = (undefined)((uint)iVar8 >> 8);
    local_22 = (undefined)(uVar4 >> 8);
    if (((param_3 == 0) &&
        (uVar7 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x20]), (uVar7 & 0xf0007) == 2)) &&
       (cVar6 = ssl3_cbc_record_digest_supported(out), cVar6 != '\0')) {
      iVar8 = ssl3_cbc_digest_record
                        (out,param_2,&local_54,&local_2d,puVar11[4],local_54 + puVar11[1],
                         uVar4 + sVar9 + (uVar5 >> 8),param_1[0x16] + 0x14,
                         *(undefined4 *)(param_1[0x16] + 0x10),0);
joined_r0x080afc79:
      if (0 < iVar8) {
        if (local_70 == 0) {
          EVP_MD_CTX_cleanup(&local_50);
        }
        sVar9 = local_54;
        if ((*param_1 != 0xfeff) && (*param_1 != 0x100)) {
          pcVar1 = (char *)((int)puVar10 + 7);
          *pcVar1 = *pcVar1 + '\x01';
          if (*pcVar1 == '\0') {
            pcVar1 = (char *)((int)puVar10 + 6);
            *pcVar1 = *pcVar1 + '\x01';
            if (*pcVar1 == '\0') {
              pcVar1 = (char *)((int)puVar10 + 5);
              *pcVar1 = *pcVar1 + '\x01';
              if (*pcVar1 == '\0') {
                puVar2 = puVar10 + 1;
                *(char *)puVar2 = *(char *)puVar2 + '\x01';
                if (*(char *)puVar2 == '\0') {
                  pcVar1 = (char *)((int)puVar10 + 3);
                  *pcVar1 = *pcVar1 + '\x01';
                  if (*pcVar1 == '\0') {
                    pcVar1 = (char *)((int)puVar10 + 2);
                    *pcVar1 = *pcVar1 + '\x01';
                    if (*pcVar1 == '\0') {
                      pcVar1 = (char *)((int)puVar10 + 1);
                      *pcVar1 = *pcVar1 + '\x01';
                      if (*pcVar1 == '\0') {
                        *(char *)puVar10 = *(char *)puVar10 + '\x01';
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto LAB_080afc8d;
      }
    }
    else {
      iVar8 = EVP_DigestUpdate(out,&local_2d,0xd);
      if ((0 < iVar8) && (iVar8 = EVP_DigestUpdate(out,(void *)puVar11[4],puVar11[1]), 0 < iVar8)) {
        iVar8 = EVP_DigestSignFinal(out,param_2,&local_54);
        goto joined_r0x080afc79;
      }
    }
    if (local_70 == 0) {
      EVP_MD_CTX_cleanup(&local_50);
    }
  }
  sVar9 = 0xffffffff;
LAB_080afc8d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return sVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

