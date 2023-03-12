
void n_ssl3_mac(int param_1,uchar *param_2,int param_3)

{
  size_t sVar1;
  EVP_MD *md;
  size_t sVar2;
  size_t __n;
  ulong uVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  undefined4 *d;
  uint *puVar8;
  EVP_MD_CTX *ctx;
  void *d_00;
  uint uVar9;
  undefined local_99;
  size_t local_98;
  size_t local_94;
  EVP_MD_CTX EStack_90;
  undefined4 auStack_78 [2];
  undefined auStack_70 [68];
  int local_2c;
  
  iVar7 = *(int *)(param_1 + 0x58);
  local_2c = __TMC_END__;
  if (param_3 == 0) {
    puVar8 = (uint *)(iVar7 + 0x10c);
    d_00 = (void *)(iVar7 + 0x14);
    ctx = *(EVP_MD_CTX **)(param_1 + 0x84);
    d = (undefined4 *)(iVar7 + 8);
  }
  else {
    ctx = *(EVP_MD_CTX **)(param_1 + 0x90);
    puVar8 = (uint *)(iVar7 + 0x130);
    d_00 = (void *)(iVar7 + 0x60);
    d = (undefined4 *)(iVar7 + 0x54);
  }
  md = EVP_MD_CTX_md(ctx);
  sVar2 = EVP_MD_size(md);
  if ((int)sVar2 < 0) {
    sVar2 = 0xffffffff;
  }
  else {
    local_98 = sVar2;
    iVar7 = __udivsi3(0x30,sVar2);
    uVar6 = puVar8[1];
    uVar9 = *puVar8;
    *puVar8 = uVar9 & 0xff;
    __n = sVar2 * iVar7;
    if (((param_3 == 0) &&
        (uVar3 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)), (uVar3 & 0xf0007) == 2)
        ) && (iVar7 = ssl3_cbc_record_digest_supported(ctx), sVar1 = local_98, iVar7 != 0)) {
      __memcpy_chk(auStack_78,d_00,local_98,0x4b);
      memcpy((void *)((int)auStack_78 + sVar1),&ssl3_pad_1,__n);
      iVar7 = __n + sVar1;
      uVar4 = d[1];
      *(undefined4 *)((int)auStack_78 + iVar7) = *d;
      *(undefined4 *)((int)auStack_78 + iVar7 + 4) = uVar4;
      auStack_70[iVar7] = (char)*puVar8;
      auStack_70[iVar7 + 1] = (char)(puVar8[1] >> 8);
      auStack_70[iVar7 + 2] = (char)puVar8[1];
      ssl3_cbc_digest_record
                (ctx,param_2,&local_98,auStack_78,puVar8[4],puVar8[1] + sVar1,
                 uVar6 + (uVar9 >> 8) + sVar2,d_00,sVar1,1);
    }
    else {
      EVP_MD_CTX_init(&EStack_90);
      EVP_MD_CTX_copy_ex(&EStack_90,ctx);
      EVP_DigestUpdate(&EStack_90,d_00,local_98);
      EVP_DigestUpdate(&EStack_90,&ssl3_pad_1,__n);
      EVP_DigestUpdate(&EStack_90,d,8);
      local_99 = (undefined)*puVar8;
      EVP_DigestUpdate(&EStack_90,&local_99,1);
      *param_2 = (uchar)(puVar8[1] >> 8);
      param_2[1] = (uchar)puVar8[1];
      EVP_DigestUpdate(&EStack_90,param_2,2);
      EVP_DigestUpdate(&EStack_90,(void *)puVar8[4],puVar8[1]);
      EVP_DigestFinal_ex(&EStack_90,param_2,(uint *)0x0);
      EVP_MD_CTX_copy_ex(&EStack_90,ctx);
      EVP_DigestUpdate(&EStack_90,d_00,local_98);
      EVP_DigestUpdate(&EStack_90,PTR_ssl3_pad_2_00050630,__n);
      EVP_DigestUpdate(&EStack_90,param_2,local_98);
      EVP_DigestFinal_ex(&EStack_90,param_2,&local_94);
      local_98 = local_94;
      EVP_MD_CTX_cleanup(&EStack_90);
    }
    cVar5 = *(char *)((int)d + 7) + '\x01';
    *(char *)((int)d + 7) = cVar5;
    sVar2 = local_98;
    if (((((cVar5 == '\0') &&
          (cVar5 = *(char *)((int)d + 6) + '\x01', *(char *)((int)d + 6) = cVar5, cVar5 == '\0')) &&
         ((cVar5 = *(char *)((int)d + 5) + '\x01', *(char *)((int)d + 5) = cVar5, cVar5 == '\0' &&
          ((cVar5 = *(char *)(d + 1), *(char *)(d + 1) = cVar5 + '\x01',
           (char)(cVar5 + '\x01') == '\0' &&
           (cVar5 = *(char *)((int)d + 3) + '\x01', *(char *)((int)d + 3) = cVar5, cVar5 == '\0'))))
         )) && (cVar5 = *(char *)((int)d + 2) + '\x01', *(char *)((int)d + 2) = cVar5, cVar5 == '\0'
               )) &&
       (cVar5 = *(char *)((int)d + 1) + '\x01', *(char *)((int)d + 1) = cVar5, cVar5 == '\0')) {
      *(char *)d = *(char *)d + '\x01';
    }
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(sVar2);
  }
  return;
}

