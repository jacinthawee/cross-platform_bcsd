
void dtls1_process_record(int param_1,uint *param_2)

{
  EVP_MD *pEVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined *b;
  uint uVar14;
  uint uVar15;
  undefined auStack_ac [64];
  undefined auStack_6c [64];
  int local_2c;
  
  iVar10 = *(int *)(param_1 + 0x58);
  iVar8 = *(int *)(param_1 + 0x4c) + 0xd;
  iVar12 = *(int *)(param_1 + 0xc0);
  local_2c = __stack_chk_guard;
  *(int *)(iVar10 + 0x11c) = iVar8;
  if (0x4540 < *(uint *)(iVar10 + 0x110)) {
    ERR_put_error(0x14,0x101,0x96,"d1_pkt.c",0x1dc);
    uVar6 = 0x16;
    goto LAB_00059a90;
  }
  iVar7 = *(int *)(param_1 + 8);
  *(int *)(iVar10 + 0x118) = iVar8;
  iVar8 = (***(code ***)(iVar7 + 100))(param_1,0);
  if (iVar8 == 0) {
    *(undefined4 *)(iVar10 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    goto LAB_00059a9a;
  }
  if (((iVar12 == 0) || (*(int *)(param_1 + 0x80) == 0)) ||
     (pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84)), pEVar1 == (EVP_MD *)0x0)) {
LAB_00059b7c:
    if (-1 < iVar8) {
      if (*(int *)(param_1 + 0x88) == 0) {
LAB_00059bbe:
        if (*(uint *)(iVar10 + 0x110) < 0x4001) {
          *(undefined4 *)(iVar10 + 0x114) = 0;
          iVar10 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(param_1 + 0x50) = 0;
          uVar13 = (uint)*(byte *)(iVar10 + 0xf) - (uint)*(byte *)((int)param_2 + 0xb);
          uVar2 = ((int)uVar13 >> 8) +
                  ((uint)*(byte *)(iVar10 + 0xe) - (uint)*(byte *)((int)param_2 + 10));
          uVar14 = ((uint)*(byte *)(iVar10 + 0xd) - (uint)*(byte *)((int)param_2 + 9)) +
                   ((int)uVar2 >> 8);
          uVar15 = ((uint)*(byte *)(iVar10 + 0xc) - (uint)*(byte *)(param_2 + 2)) +
                   ((int)uVar14 >> 8);
          uVar11 = ((uint)*(byte *)(iVar10 + 0xb) - (uint)*(byte *)((int)param_2 + 7)) +
                   ((int)uVar15 >> 8);
          uVar4 = ((uint)*(byte *)(iVar10 + 10) - (uint)*(byte *)((int)param_2 + 6)) +
                  ((int)uVar11 >> 8);
          if ((uVar13 & 0x80) == 0) {
            uVar9 = ((uint)*(byte *)(iVar10 + 9) - (uint)*(byte *)((int)param_2 + 5)) +
                    ((int)uVar4 >> 8);
            uVar5 = ((uint)*(byte *)(iVar10 + 8) - (uint)*(byte *)(param_2 + 1)) + ((int)uVar9 >> 8)
            ;
            uVar2 = uVar9 | uVar4 | uVar2 | uVar14 | uVar15 | uVar11 | uVar5;
          }
          else {
            uVar9 = ((uint)*(byte *)(iVar10 + 9) - (uint)*(byte *)((int)param_2 + 5)) +
                    ((int)uVar4 >> 8);
            uVar5 = ((uint)*(byte *)(iVar10 + 8) - (uint)*(byte *)(param_2 + 1)) + ((int)uVar9 >> 8)
            ;
            uVar2 = ~uVar2 | ~uVar14 | ~uVar15 | ~uVar11 | ~uVar4 | ~uVar9 | ~uVar5;
          }
          uVar4 = ((int)uVar5 >> 8) * 0x100;
          if ((uVar2 & 0xff) == 0) {
            uVar4 = uVar4 + (uVar13 & 0xff);
          }
          else {
            uVar4 = uVar4 | 0x80;
          }
          if ((int)uVar4 < 1) {
            iVar8 = 1;
            if (-uVar4 < 0x1f || uVar4 == 0xffffffe1) {
              *param_2 = *param_2 | 1 << (-uVar4 & 0xff);
            }
          }
          else {
            iVar8 = 1;
            if (uVar4 < 0x20) {
              uVar2 = *param_2 << (uVar4 & 0xff) | 1;
            }
            else {
              uVar2 = 1;
            }
            *param_2 = uVar2;
            uVar2 = *(uint *)(iVar10 + 0xc);
            param_2[1] = *(uint *)(iVar10 + 8);
            param_2[2] = uVar2;
          }
          goto LAB_00059a9a;
        }
        ERR_put_error(0x14,0x101,0x92,"d1_pkt.c",0x24b);
        uVar6 = 0x16;
      }
      else if (*(uint *)(iVar10 + 0x110) < 0x4401) {
        iVar8 = ssl3_do_uncompress(param_1);
        if (iVar8 != 0) goto LAB_00059bbe;
        ERR_put_error(0x14,0x101,0x6b,"d1_pkt.c",0x244);
        uVar6 = 0x1e;
      }
      else {
        ERR_put_error(0x14,0x101,0x8c,"d1_pkt.c",0x23f);
        uVar6 = 0x16;
      }
LAB_00059a90:
      ssl3_send_alert(param_1,2,uVar6);
      iVar8 = 0;
      goto LAB_00059a9a;
    }
  }
  else {
    pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
    uVar2 = EVP_MD_size(pEVar1);
    if (0x40 < uVar2) {
      OpenSSLDie("d1_pkt.c",0x201,"mac_size <= EVP_MAX_MD_SIZE");
    }
    uVar13 = *(int *)(iVar10 + 0x110) + (*(uint *)(iVar10 + 0x10c) >> 8);
    if ((uVar13 < uVar2) ||
       ((uVar3 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)), (uVar3 & 0xf0007) == 2
        && (uVar13 < uVar2 + 1)))) {
      ERR_put_error(0x14,0x101,0xa0,"d1_pkt.c",0x213);
      uVar6 = 0x32;
      goto LAB_00059a90;
    }
    uVar3 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
    if ((uVar3 & 0xf0007) == 2) {
      b = auStack_6c;
      ssl3_cbc_copy_mac(b,iVar10 + 0x10c,uVar2,uVar13);
      uVar13 = 0;
      *(uint *)(iVar10 + 0x110) = *(int *)(iVar10 + 0x110) - uVar2;
    }
    else {
      iVar12 = *(int *)(iVar10 + 0x110) - uVar2;
      *(int *)(iVar10 + 0x110) = iVar12;
      b = (undefined *)(*(int *)(iVar10 + 0x118) + iVar12);
      if (b == (undefined *)0x0) {
        uVar13 = 1;
      }
      else {
        uVar13 = 0;
      }
    }
    uVar4 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 4))(param_1,auStack_ac,0);
    if ((uVar13 | uVar4 >> 0x1f) == 0) {
      iVar12 = CRYPTO_memcmp(auStack_ac,b,uVar2);
      if (iVar12 != 0) {
        iVar8 = -1;
      }
    }
    else {
      iVar8 = -1;
    }
    if (*(uint *)(iVar10 + 0x110) <= uVar2 + 0x4400) goto LAB_00059b7c;
  }
  iVar8 = 0;
  *(undefined4 *)(iVar10 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
LAB_00059a9a:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar8);
}

