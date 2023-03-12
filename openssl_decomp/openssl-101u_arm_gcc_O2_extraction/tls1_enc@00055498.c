
void tls1_enc(int *param_1,int param_2)

{
  undefined2 uVar1;
  undefined uVar2;
  EVP_MD *pEVar3;
  int iVar4;
  EVP_CIPHER_CTX *cipher;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char cVar9;
  int extraout_r1;
  int extraout_r1_00;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  EVP_CIPHER_CTX *ctx;
  uint uVar13;
  undefined2 uStack_46;
  undefined2 uStack_44;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_2 == 0) {
    pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
    if (pEVar3 != (EVP_MD *)0x0) {
      pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
      iVar4 = EVP_MD_size(pEVar3);
      if (iVar4 < 0) {
        OpenSSLDie("t1_enc.c",0x307,"n >= 0");
      }
    }
    ctx = (EVP_CIPHER_CTX *)param_1[0x20];
    puVar12 = (undefined4 *)(param_1[0x16] + 0x10c);
    cipher = ctx;
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      cipher = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx);
    }
LAB_00055574:
    if ((param_1[0x30] == 0) || (cipher == (EVP_CIPHER_CTX *)0x0 || ctx == (EVP_CIPHER_CTX *)0x0)) {
      memmove((void *)puVar12[3],(void *)puVar12[4],puVar12[1]);
      puVar12[4] = puVar12[3];
      uVar13 = 1;
      goto LAB_00055594;
    }
    uVar13 = puVar12[1];
    iVar4 = EVP_CIPHER_block_size(ctx->cipher);
    uVar5 = EVP_CIPHER_flags(ctx->cipher);
    uVar7 = uVar13;
    if ((int)(uVar5 << 10) < 0) {
      iVar6 = *param_1;
      if (param_2 == 0) {
        puVar10 = (undefined4 *)(param_1[0x16] + 8);
        if (iVar6 == 0x100 || iVar6 == 0xfeff) {
          uVar1 = *(undefined2 *)(param_1[0x17] + 0x208);
          uVar2 = (undefined)uVar1;
          goto LAB_000556e4;
        }
LAB_000557ac:
        uStack_38 = puVar10[1];
        local_3c = *puVar10;
        cVar9 = *(char *)((int)puVar10 + 7) + '\x01';
        *(char *)((int)puVar10 + 7) = cVar9;
        if (((cVar9 == '\0') &&
            (cVar9 = *(char *)((int)puVar10 + 6) + '\x01', *(char *)((int)puVar10 + 6) = cVar9,
            cVar9 == '\0')) &&
           ((cVar9 = *(char *)((int)puVar10 + 5) + '\x01', *(char *)((int)puVar10 + 5) = cVar9,
            cVar9 == '\0' &&
            ((((cVar9 = *(char *)(puVar10 + 1), *(char *)(puVar10 + 1) = cVar9 + '\x01',
               (char)(cVar9 + '\x01') == '\0' &&
               (cVar9 = *(char *)((int)puVar10 + 3) + '\x01', *(char *)((int)puVar10 + 3) = cVar9,
               cVar9 == '\0')) &&
              (cVar9 = *(char *)((int)puVar10 + 2) + '\x01', *(char *)((int)puVar10 + 2) = cVar9,
              cVar9 == '\0')) &&
             (cVar9 = *(char *)((int)puVar10 + 1) + '\x01', *(char *)((int)puVar10 + 1) = cVar9,
             cVar9 == '\0')))))) {
          *(char *)puVar10 = *(char *)puVar10 + '\x01';
        }
        iVar6 = *param_1;
      }
      else {
        puVar10 = (undefined4 *)(param_1[0x16] + 0x54);
        if (iVar6 != 0xfeff && iVar6 != 0x100) goto LAB_000557ac;
        uVar1 = *(undefined2 *)(param_1[0x17] + 0x20a);
        uVar2 = (undefined)uVar1;
LAB_000556e4:
        uStack_46 = (undefined2)*(undefined4 *)((int)puVar10 + 2);
        uStack_44 = (undefined2)((uint)*(undefined4 *)((int)puVar10 + 2) >> 0x10);
        local_3c = CONCAT22(uStack_46,CONCAT11(uVar2,(char)((ushort)uVar1 >> 8)));
        uStack_38 = CONCAT22(*(undefined2 *)((int)puVar10 + 6),uStack_44);
      }
      local_32 = (undefined)iVar6;
      local_33 = (undefined)((uint)iVar6 >> 8);
      local_34 = (undefined)*puVar12;
      local_30 = (undefined)puVar12[1];
      local_31 = (undefined)((uint)puVar12[1] >> 8);
      iVar8 = EVP_CIPHER_CTX_ctrl(ctx,0x16,0xd,&local_3c);
      if (iVar8 < 1) goto LAB_00055820;
      if (param_2 != 0) {
        puVar12[1] = puVar12[1] + iVar8;
        uVar7 = uVar13 + iVar8;
        goto LAB_00055748;
      }
LAB_00055750:
      uVar13 = uVar7;
      if (uVar7 == 0) goto LAB_00055594;
      __aeabi_uidivmod(uVar7,iVar4);
      uVar13 = 0;
      if (extraout_r1_00 != 0) goto LAB_00055594;
    }
    else if (iVar4 == 1 || param_2 == 0) {
      iVar8 = 0;
LAB_00055748:
      if (param_2 == 0) goto LAB_00055750;
    }
    else {
      __aeabi_idivmod(uVar13,iVar4);
      iVar6 = iVar4 - extraout_r1;
      uVar2 = (undefined)(iVar6 + -1);
      if (param_1[0x40] << 0x16 < 0) {
        iVar8 = iVar6 + -1;
        if ((*(uint *)param_1[0x16] & 8) != 0) {
          iVar8 = iVar6;
        }
        uVar2 = (undefined)iVar8;
      }
      uVar7 = uVar13 + iVar6;
      if ((int)uVar13 < (int)uVar7) {
        do {
          *(undefined *)(puVar12[4] + uVar13) = uVar2;
          uVar13 = uVar13 + 1;
        } while (uVar13 != uVar7);
      }
      iVar8 = 0;
      puVar12[1] = iVar6 + puVar12[1];
    }
    uVar7 = EVP_Cipher(ctx,(uchar *)puVar12[3],(uchar *)puVar12[4],uVar7);
    uVar5 = EVP_CIPHER_flags(ctx->cipher);
    if ((int)(uVar5 << 0xb) < 0) {
      uVar7 = uVar7 >> 0x1f;
    }
    else {
      uVar7 = count_leading_zeroes(uVar7);
      uVar7 = uVar7 >> 5;
    }
    if (uVar7 == 0) {
      uVar5 = EVP_CIPHER_flags((EVP_CIPHER *)cipher);
      if (((uVar5 & 0xf0007) == 6) && (param_2 == 0)) {
        puVar12[3] = puVar12[3] + 8;
        puVar12[4] = puVar12[4] + 8;
        puVar12[1] = puVar12[1] + -8;
      }
      pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
      if (pEVar3 != (EVP_MD *)0x0) {
        pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
        EVP_MD_size(pEVar3);
      }
      uVar7 = count_leading_zeroes(param_2);
      uVar13 = 1;
      if (iVar4 == 1) {
        uVar11 = 0;
      }
      else {
        uVar11 = uVar7 >> 5 & 1;
      }
      if (uVar11 != 0) {
        uVar13 = tls1_cbc_remove_padding(param_1,puVar12,iVar4);
      }
      if (iVar8 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = uVar7 >> 5 & 1;
      }
      if (uVar7 != 0) {
        puVar12[1] = puVar12[1] - iVar8;
      }
      goto LAB_00055594;
    }
  }
  else {
    pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
    if (pEVar3 != (EVP_MD *)0x0) {
      pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x24]);
      iVar4 = EVP_MD_size(pEVar3);
      if (iVar4 < 0) {
        OpenSSLDie("t1_enc.c",0x2e8,"n >= 0");
      }
    }
    ctx = (EVP_CIPHER_CTX *)param_1[0x23];
    iVar4 = param_1[0x16];
    puVar12 = (undefined4 *)(iVar4 + 0x130);
    cipher = ctx;
    if ((((ctx == (EVP_CIPHER_CTX *)0x0) ||
         (cipher = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx), *param_1 < 0x302)) ||
        (uVar5 = EVP_CIPHER_flags((EVP_CIPHER *)cipher), (uVar5 & 0xf0007) != 2)) ||
       (iVar6 = EVP_CIPHER_iv_length((EVP_CIPHER *)cipher), iVar6 < 2)) goto LAB_00055574;
    if (*(uchar **)(iVar4 + 0x13c) != *(uchar **)(iVar4 + 0x140)) {
      __fprintf_chk(stderr,1,"%s:%d: rec->data != rec->input\n","t1_enc.c",0x2ff);
      goto LAB_00055574;
    }
    iVar4 = RAND_bytes(*(uchar **)(iVar4 + 0x13c),iVar6);
    if (0 < iVar4) goto LAB_00055574;
  }
LAB_00055820:
  uVar13 = 0xffffffff;
LAB_00055594:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
}

