
void tls1_mac(int *param_1,uchar *param_2,int param_3)

{
  undefined2 uVar1;
  size_t sVar2;
  EVP_MD *pEVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  undefined4 *puVar9;
  uint *puVar10;
  EVP_MD_CTX *ctx;
  EVP_MD_CTX *out;
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
  
  iVar8 = param_1[0x16];
  local_2c = __TMC_END__;
  if (param_3 == 0) {
    ctx = (EVP_MD_CTX *)param_1[0x21];
    uVar11 = param_1[0x1f] & 1;
    puVar10 = (uint *)(iVar8 + 0x10c);
    puVar9 = (undefined4 *)(iVar8 + 8);
    pEVar3 = EVP_MD_CTX_md(ctx);
    local_64 = EVP_MD_size(pEVar3);
  }
  else {
    ctx = (EVP_MD_CTX *)param_1[0x24];
    uVar11 = param_1[0x1f] & 2;
    puVar10 = (uint *)(iVar8 + 0x130);
    puVar9 = (undefined4 *)(iVar8 + 0x54);
    pEVar3 = EVP_MD_CTX_md(ctx);
    local_64 = EVP_MD_size(pEVar3);
  }
  if ((int)local_64 < 0) {
    OpenSSLDie("t1_enc.c",0x3d3,"t >= 0");
  }
  out = ctx;
  if (uVar11 == 0) {
    out = &EStack_60;
    EVP_MD_CTX_copy(out,ctx);
  }
  sVar2 = local_64;
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
    local_42 = *(undefined2 *)((int)puVar9 + 6);
    uStack_46 = (undefined2)*(undefined4 *)((int)puVar9 + 2);
    uStack_44 = (undefined2)((uint)*(undefined4 *)((int)puVar9 + 2) >> 0x10);
    local_3c = CONCAT22(uStack_46,CONCAT11(uStack_47,local_48));
    uStack_38 = CONCAT22(local_42,uStack_44);
  }
  else {
    local_3c = *puVar9;
    uStack_38 = puVar9[1];
  }
  uVar12 = *puVar10;
  uVar6 = puVar10[1];
  uVar4 = uVar12 & 0xff;
  *puVar10 = uVar4;
  local_34 = (undefined)uVar4;
  local_30 = (undefined)uVar6;
  local_32 = (undefined)iVar8;
  local_33 = (undefined)((uint)iVar8 >> 8);
  local_31 = (undefined)(uVar6 >> 8);
  if (((param_3 == 0) &&
      (uVar5 = EVP_CIPHER_CTX_flags((EVP_CIPHER_CTX *)param_1[0x20]), (uVar5 & 0xf0007) == 2)) &&
     (iVar8 = ssl3_cbc_record_digest_supported(out), iVar8 != 0)) {
    ssl3_cbc_digest_record
              (out,param_2,&local_64,&local_3c,puVar10[4],local_64 + puVar10[1],
               uVar6 + sVar2 + (uVar12 >> 8),param_1[0x16] + 0x14,
               *(undefined4 *)(param_1[0x16] + 0x10),0);
  }
  else {
    EVP_DigestUpdate(out,&local_3c,0xd);
    EVP_DigestUpdate(out,(void *)puVar10[4],puVar10[1]);
    iVar8 = EVP_DigestSignFinal(out,param_2,&local_64);
    if (iVar8 < 1) {
      OpenSSLDie("t1_enc.c",0x40d,"t > 0");
    }
  }
  if (uVar11 == 0) {
    EVP_MD_CTX_cleanup(&EStack_60);
  }
  if (((((*param_1 != 0x100 && *param_1 != 0xfeff) &&
        (cVar7 = *(char *)((int)puVar9 + 7) + '\x01', *(char *)((int)puVar9 + 7) = cVar7,
        cVar7 == '\0')) &&
       ((cVar7 = *(char *)((int)puVar9 + 6) + '\x01', *(char *)((int)puVar9 + 6) = cVar7,
        cVar7 == '\0' &&
        ((cVar7 = *(char *)((int)puVar9 + 5) + '\x01', *(char *)((int)puVar9 + 5) = cVar7,
         cVar7 == '\0' &&
         (cVar7 = *(char *)(puVar9 + 1), *(char *)(puVar9 + 1) = cVar7 + '\x01',
         (char)(cVar7 + '\x01') == '\0')))))) &&
      (cVar7 = *(char *)((int)puVar9 + 3) + '\x01', *(char *)((int)puVar9 + 3) = cVar7,
      cVar7 == '\0')) &&
     ((cVar7 = *(char *)((int)puVar9 + 2) + '\x01', *(char *)((int)puVar9 + 2) = cVar7,
      cVar7 == '\0' &&
      (cVar7 = *(char *)((int)puVar9 + 1) + '\x01', *(char *)((int)puVar9 + 1) = cVar7,
      cVar7 == '\0')))) {
    *(char *)puVar9 = *(char *)puVar9 + '\x01';
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_64);
}

