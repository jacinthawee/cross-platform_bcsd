
void tls1_mac(int *param_1,uchar *param_2,int param_3)

{
  undefined2 uVar1;
  EVP_MD *pEVar2;
  uint uVar3;
  ulong uVar4;
  size_t sVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  uint *puVar9;
  EVP_MD_CTX *ctx;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  size_t local_64;
  EVP_MD_CTX EStack_60;
  undefined local_48;
  undefined uStack_47;
  undefined2 uStack_46;
  undefined2 uStack_44;
  undefined2 local_42;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar8 = param_1[0x16];
  if (param_3 == 0) {
    ctx = (EVP_MD_CTX *)param_1[0x21];
    puVar9 = (uint *)(iVar8 + 0x10c);
    puVar10 = (undefined4 *)(iVar8 + 8);
    uVar11 = param_1[0x1f] & 1;
    pEVar2 = EVP_MD_CTX_md(ctx);
    local_64 = EVP_MD_size(pEVar2);
    if (-1 < (int)local_64) goto LAB_00055bd4;
LAB_00055d5a:
    OpenSSLDie("t1_enc.c",0x3f4,"t >= 0");
    if (uVar11 != 0) goto LAB_00055bde;
LAB_00055d80:
    iVar8 = EVP_MD_CTX_copy(&EStack_60,ctx);
    ctx = &EStack_60;
    if (iVar8 != 0) goto LAB_00055bde;
  }
  else {
    ctx = (EVP_MD_CTX *)param_1[0x24];
    puVar9 = (uint *)(iVar8 + 0x130);
    puVar10 = (undefined4 *)(iVar8 + 0x54);
    uVar11 = param_1[0x1f] & 2;
    pEVar2 = EVP_MD_CTX_md(ctx);
    local_64 = EVP_MD_size(pEVar2);
    if ((int)local_64 < 0) goto LAB_00055d5a;
LAB_00055bd4:
    if (uVar11 == 0) goto LAB_00055d80;
LAB_00055bde:
    sVar5 = local_64;
    iVar8 = *param_1;
    if (iVar8 == 0xfeff || iVar8 == 0x100) {
      if (param_3 == 0) {
        uVar1 = *(undefined2 *)(param_1[0x17] + 0x208);
        uStack_47 = (undefined)uVar1;
        local_48 = (undefined)((ushort)uVar1 >> 8);
      }
      else {
        uVar1 = *(undefined2 *)(param_1[0x17] + 0x20a);
        uStack_47 = (undefined)uVar1;
        local_48 = (undefined)((ushort)uVar1 >> 8);
      }
      local_42 = *(undefined2 *)((int)puVar10 + 6);
      uStack_46 = (undefined2)*(undefined4 *)((int)puVar10 + 2);
      uStack_44 = (undefined2)((uint)*(undefined4 *)((int)puVar10 + 2) >> 0x10);
      local_3c = CONCAT22(uStack_46,CONCAT11(uStack_47,local_48));
      uStack_38 = CONCAT22(local_42,uStack_44);
    }
    else {
      local_3c = *puVar10;
      uStack_38 = puVar10[1];
    }
    uVar12 = *puVar9;
    uVar6 = puVar9[1];
    uVar3 = uVar12 & 0xff;
    *puVar9 = uVar3;
    local_34 = (undefined)uVar3;
    local_30 = (undefined)uVar6;
    local_32 = (undefined)iVar8;
    local_33 = (undefined)((uint)iVar8 >> 8);
    local_31 = (undefined)(uVar6 >> 8);
    if (((param_3 == 0) &&
        (uVar4 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x20]), (uVar4 & 0xf0007) == 2)) &&
       (iVar8 = ssl3_cbc_record_digest_supported(ctx), iVar8 != 0)) {
      iVar8 = ssl3_cbc_digest_record
                        (ctx,param_2,&local_64,&local_3c,puVar9[4],local_64 + puVar9[1],
                         uVar6 + sVar5 + (uVar12 >> 8),param_1[0x16] + 0x14,
                         *(undefined4 *)(param_1[0x16] + 0x10),0);
joined_r0x00055de8:
      if (0 < iVar8) {
        if (uVar11 == 0) {
          EVP_MD_CTX_cleanup(&EStack_60);
        }
        sVar5 = local_64;
        if (((*param_1 != 0x100 && *param_1 != 0xfeff) &&
            (cVar7 = *(char *)((int)puVar10 + 7) + '\x01', *(char *)((int)puVar10 + 7) = cVar7,
            cVar7 == '\0')) &&
           ((cVar7 = *(char *)((int)puVar10 + 6) + '\x01', *(char *)((int)puVar10 + 6) = cVar7,
            cVar7 == '\0' &&
            ((((cVar7 = *(char *)((int)puVar10 + 5) + '\x01', *(char *)((int)puVar10 + 5) = cVar7,
               cVar7 == '\0' &&
               (cVar7 = *(char *)(puVar10 + 1), *(char *)(puVar10 + 1) = cVar7 + '\x01',
               (char)(cVar7 + '\x01') == '\0')) &&
              (cVar7 = *(char *)((int)puVar10 + 3) + '\x01', *(char *)((int)puVar10 + 3) = cVar7,
              cVar7 == '\0')) &&
             ((cVar7 = *(char *)((int)puVar10 + 2) + '\x01', *(char *)((int)puVar10 + 2) = cVar7,
              cVar7 == '\0' &&
              (cVar7 = *(char *)((int)puVar10 + 1) + '\x01', *(char *)((int)puVar10 + 1) = cVar7,
              cVar7 == '\0')))))))) {
          *(char *)puVar10 = *(char *)puVar10 + '\x01';
        }
        goto LAB_00055d2c;
      }
    }
    else {
      iVar8 = EVP_DigestUpdate(ctx,&local_3c,0xd);
      if ((0 < iVar8) && (iVar8 = EVP_DigestUpdate(ctx,(void *)puVar9[4],puVar9[1]), 0 < iVar8)) {
        iVar8 = EVP_DigestSignFinal(ctx,param_2,&local_64);
        goto joined_r0x00055de8;
      }
    }
    if (uVar11 == 0) {
      EVP_MD_CTX_cleanup(&EStack_60);
    }
  }
  sVar5 = 0xffffffff;
LAB_00055d2c:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(sVar5);
  }
  return;
}

