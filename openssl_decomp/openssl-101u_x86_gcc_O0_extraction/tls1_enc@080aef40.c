
/* WARNING: Could not reconcile some variable overlaps */

undefined4 tls1_enc(int *param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  EVP_MD *pEVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined uVar9;
  undefined4 *puVar10;
  EVP_CIPHER_CTX *ctx;
  uint uVar11;
  int in_GS_OFFSET;
  bool bVar12;
  int local_4c;
  EVP_CIPHER *local_48;
  uint local_44;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined4 local_2d;
  undefined4 local_29;
  undefined local_25;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
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
    puVar10 = (undefined4 *)(param_1[0x16] + 0x10c);
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      local_48 = EVP_CIPHER_CTX_cipher(ctx);
      goto LAB_080af0f0;
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
    puVar10 = (undefined4 *)(iVar4 + 0x130);
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      local_48 = EVP_CIPHER_CTX_cipher(ctx);
      if (((*param_1 < 0x302) || (uVar5 = EVP_CIPHER_flags(local_48), (uVar5 & 0xf0007) != 2)) ||
         (iVar6 = EVP_CIPHER_iv_length(local_48), iVar6 < 2)) {
LAB_080af0f0:
        if ((param_1[0x30] == 0) || (local_48 == (EVP_CIPHER *)0x0)) goto LAB_080af0a3;
        uVar11 = puVar10[1];
        uVar7 = EVP_CIPHER_block_size(ctx->cipher);
        uVar5 = EVP_CIPHER_flags(ctx->cipher);
        local_44 = uVar11;
        if ((uVar5 & 0x200000) == 0) {
          if ((uVar7 == 1) || (param_2 == 0)) {
            iVar4 = 0;
LAB_080af224:
            if (param_2 == 0) goto LAB_080af230;
          }
          else {
            iVar4 = uVar7 - (int)uVar11 % (int)uVar7;
            uVar9 = (undefined)(iVar4 + -1);
            if ((*(byte *)((int)param_1 + 0x101) & 2) != 0) {
              iVar6 = iVar4 + -1;
              if ((*(byte *)param_1[0x16] & 8) != 0) {
                iVar6 = iVar4;
              }
              uVar9 = (undefined)iVar6;
            }
            local_44 = uVar11 + iVar4;
            if ((int)uVar11 < (int)local_44) {
              do {
                *(undefined *)(puVar10[4] + uVar11) = uVar9;
                uVar11 = uVar11 + 1;
              } while (uVar11 != local_44);
            }
            puVar10[1] = puVar10[1] + iVar4;
            iVar4 = 0;
          }
        }
        else {
          if (param_2 == 0) {
            local_4c = *param_1;
            puVar8 = (undefined4 *)(param_1[0x16] + 8);
            if ((local_4c != 0x100) && (local_4c != 0xfeff)) goto LAB_080af15c;
            uVar2 = *(undefined2 *)(param_1[0x17] + 0x208);
            uVar9 = (undefined)((ushort)uVar2 >> 8);
LAB_080af3cb:
            uStack_34 = (undefined2)*(undefined4 *)((int)puVar8 + 2);
            uStack_32 = (undefined2)((uint)*(undefined4 *)((int)puVar8 + 2) >> 0x10);
            local_2d = CONCAT22(uStack_34,CONCAT11((char)uVar2,uVar9));
            local_29 = CONCAT22(*(undefined2 *)((int)puVar8 + 6),uStack_32);
          }
          else {
            local_4c = *param_1;
            puVar8 = (undefined4 *)(param_1[0x16] + 0x54);
            if ((local_4c == 0xfeff) || (local_4c == 0x100)) {
              uVar2 = *(undefined2 *)(param_1[0x17] + 0x20a);
              uVar9 = (undefined)((ushort)uVar2 >> 8);
              goto LAB_080af3cb;
            }
LAB_080af15c:
            local_29 = puVar8[1];
            local_2d = *puVar8;
            cVar1 = *(char *)((int)puVar8 + 7) + '\x01';
            *(char *)((int)puVar8 + 7) = cVar1;
            if (((cVar1 == '\0') &&
                ((((cVar1 = *(char *)((int)puVar8 + 6) + '\x01', *(char *)((int)puVar8 + 6) = cVar1,
                   cVar1 == '\0' &&
                   (cVar1 = *(char *)((int)puVar8 + 5) + '\x01', *(char *)((int)puVar8 + 5) = cVar1,
                   cVar1 == '\0')) &&
                  (cVar1 = *(char *)(puVar8 + 1), *(char *)(puVar8 + 1) = cVar1 + '\x01',
                  (char)(cVar1 + '\x01') == '\0')) &&
                 ((cVar1 = *(char *)((int)puVar8 + 3) + '\x01', *(char *)((int)puVar8 + 3) = cVar1,
                  cVar1 == '\0' &&
                  (cVar1 = *(char *)((int)puVar8 + 2) + '\x01', *(char *)((int)puVar8 + 2) = cVar1,
                  cVar1 == '\0')))))) &&
               (cVar1 = *(char *)((int)puVar8 + 1) + '\x01', *(char *)((int)puVar8 + 1) = cVar1,
               cVar1 == '\0')) {
              *(char *)puVar8 = *(char *)puVar8 + '\x01';
            }
            local_4c._0_2_ = (undefined2)*param_1;
          }
          local_23 = (undefined)(undefined2)local_4c;
          local_25 = (undefined)*puVar10;
          local_24 = (undefined)((ushort)(undefined2)local_4c >> 8);
          local_21 = (undefined)puVar10[1];
          local_22 = (undefined)((uint)puVar10[1] >> 8);
          iVar4 = EVP_CIPHER_CTX_ctrl(ctx,0x16,0xd,&local_2d);
          if (iVar4 < 1) goto LAB_080af4a0;
          if (param_2 != 0) {
            puVar10[1] = puVar10[1] + iVar4;
            local_44 = uVar11 + iVar4;
            goto LAB_080af224;
          }
LAB_080af230:
          local_4c = 0;
          if ((local_44 == 0) || (local_44 % uVar7 != 0)) goto LAB_080af0c4;
        }
        iVar6 = EVP_Cipher(ctx,(uchar *)puVar10[3],(uchar *)puVar10[4],local_44);
        uVar5 = EVP_CIPHER_flags(ctx->cipher);
        if ((uVar5 & 0x100000) == 0) {
          bVar12 = iVar6 == 0;
        }
        else {
          bVar12 = SUB41((uint)iVar6 >> 0x1f,0);
        }
        if (bVar12 == false) {
          uVar5 = EVP_CIPHER_flags(local_48);
          bVar12 = param_2 == 0;
          if (((uVar5 & 0xf0007) == 6) && (bVar12)) {
            puVar10[3] = puVar10[3] + 8;
            puVar10[4] = puVar10[4] + 8;
            puVar10[1] = puVar10[1] + -8;
          }
          pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
          iVar6 = 0;
          if (pEVar3 != (EVP_MD *)0x0) {
            pEVar3 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0x21]);
            iVar6 = EVP_MD_size(pEVar3);
          }
          if ((uVar7 == 1) || (!bVar12)) {
            local_4c = 1;
          }
          else {
            local_4c = tls1_cbc_remove_padding(param_1,puVar10,uVar7,iVar6);
          }
          if ((iVar4 != 0) && (bVar12)) {
            puVar10[1] = puVar10[1] - iVar4;
          }
          goto LAB_080af0c4;
        }
      }
      else {
        if (*(uchar **)(iVar4 + 0x13c) != *(uchar **)(iVar4 + 0x140)) {
          __fprintf_chk(stderr,1,"%s:%d: rec->data != rec->input\n","t1_enc.c",0x2ff);
          goto LAB_080af0f0;
        }
        iVar4 = RAND_bytes(*(uchar **)(iVar4 + 0x13c),iVar6);
        if (0 < iVar4) goto LAB_080af0f0;
      }
LAB_080af4a0:
      local_4c = 0xffffffff;
      goto LAB_080af0c4;
    }
  }
LAB_080af0a3:
  memmove((void *)puVar10[3],(void *)puVar10[4],puVar10[1]);
  local_4c = 1;
  puVar10[4] = puVar10[3];
LAB_080af0c4:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_4c;
}

