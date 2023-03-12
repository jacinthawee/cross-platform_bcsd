
void dtls1_process_record(int param_1)

{
  EVP_MD *pEVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined *b;
  uint uVar14;
  uint uVar15;
  undefined auStack_ac [64];
  undefined auStack_6c [64];
  int local_2c;
  
  iVar10 = *(int *)(param_1 + 0x58);
  iVar9 = *(int *)(param_1 + 0x4c) + 0xd;
  iVar11 = *(int *)(param_1 + 0xc0);
  local_2c = __TMC_END__;
  *(int *)(iVar10 + 0x11c) = iVar9;
  if (0x4540 < *(uint *)(iVar10 + 0x110)) {
    ERR_put_error(0x14,0x101,0x96,"d1_pkt.c",0x197);
    uVar6 = 0x16;
    goto LAB_0005c0fa;
  }
  iVar7 = *(int *)(param_1 + 8);
  *(int *)(iVar10 + 0x118) = iVar9;
  iVar9 = (***(code ***)(iVar7 + 100))(param_1,0);
  if (iVar9 == 0) {
    *(undefined4 *)(iVar10 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    goto LAB_0005c104;
  }
  if (((iVar11 == 0) || (*(int *)(param_1 + 0x80) == 0)) ||
     (pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84)), pEVar1 == (EVP_MD *)0x0)) {
LAB_0005c1e6:
    if (-1 < iVar9) {
      if (*(int *)(param_1 + 0x88) == 0) {
LAB_0005c228:
        if (*(uint *)(iVar10 + 0x110) < 0x4001) {
          iVar11 = *(int *)(param_1 + 0x5c);
          *(undefined4 *)(iVar10 + 0x114) = 0;
          iVar10 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(param_1 + 0x50) = 0;
          uVar13 = (uint)*(byte *)(iVar10 + 0xf) - (uint)*(byte *)(iVar11 + 0x217);
          uVar2 = ((int)uVar13 >> 8) +
                  ((uint)*(byte *)(iVar10 + 0xe) - (uint)*(byte *)(iVar11 + 0x216));
          uVar12 = ((uint)*(byte *)(iVar10 + 0xd) - (uint)*(byte *)(iVar11 + 0x215)) +
                   ((int)uVar2 >> 8);
          uVar14 = ((uint)*(byte *)(iVar10 + 0xc) - (uint)*(byte *)(iVar11 + 0x214)) +
                   ((int)uVar12 >> 8);
          uVar15 = ((uint)*(byte *)(iVar10 + 0xb) - (uint)*(byte *)(iVar11 + 0x213)) +
                   ((int)uVar14 >> 8);
          uVar4 = ((uint)*(byte *)(iVar10 + 10) - (uint)*(byte *)(iVar11 + 0x212)) +
                  ((int)uVar15 >> 8);
          if ((uVar13 & 0x80) == 0) {
            uVar8 = ((uint)*(byte *)(iVar10 + 9) - (uint)*(byte *)(iVar11 + 0x211)) +
                    ((int)uVar4 >> 8);
            uVar5 = ((uint)*(byte *)(iVar10 + 8) - (uint)*(byte *)(iVar11 + 0x210)) +
                    ((int)uVar8 >> 8);
            uVar2 = uVar8 | uVar2 | uVar12 | uVar14 | uVar15 | uVar4 | uVar5;
          }
          else {
            uVar8 = ((uint)*(byte *)(iVar10 + 9) - (uint)*(byte *)(iVar11 + 0x211)) +
                    ((int)uVar4 >> 8);
            uVar5 = ((uint)*(byte *)(iVar10 + 8) - (uint)*(byte *)(iVar11 + 0x210)) +
                    ((int)uVar8 >> 8);
            uVar2 = ~uVar2 | ~uVar12 | ~uVar14 | ~uVar15 | ~uVar4 | ~uVar8 | ~uVar5;
          }
          uVar4 = ((int)uVar5 >> 8) * 0x100;
          if ((uVar2 & 0xff) == 0) {
            uVar4 = uVar4 + (uVar13 & 0xff);
          }
          else {
            uVar4 = uVar4 | 0x80;
          }
          if ((int)uVar4 < 1) {
            iVar9 = 1;
            if (-uVar4 < 0x1f || uVar4 == 0xffffffe1) {
              *(uint *)(iVar11 + 0x20c) = *(uint *)(iVar11 + 0x20c) | 1 << (-uVar4 & 0xff);
            }
          }
          else {
            iVar9 = 1;
            if (uVar4 < 0x20) {
              uVar2 = *(int *)(iVar11 + 0x20c) << (uVar4 & 0xff) | 1;
            }
            else {
              uVar2 = 1;
            }
            *(uint *)(iVar11 + 0x20c) = uVar2;
            uVar6 = *(undefined4 *)(iVar10 + 0xc);
            *(undefined4 *)(iVar11 + 0x210) = *(undefined4 *)(iVar10 + 8);
            *(undefined4 *)(iVar11 + 0x214) = uVar6;
          }
          goto LAB_0005c104;
        }
        ERR_put_error(0x14,0x101,0x92,"d1_pkt.c",0x205);
        uVar6 = 0x16;
      }
      else if (*(uint *)(iVar10 + 0x110) < 0x4401) {
        iVar9 = ssl3_do_uncompress(param_1);
        if (iVar9 != 0) goto LAB_0005c228;
        ERR_put_error(0x14,0x101,0x6b,"d1_pkt.c",0x1fd);
        uVar6 = 0x1e;
      }
      else {
        ERR_put_error(0x14,0x101,0x8c,"d1_pkt.c",0x1f7);
        uVar6 = 0x16;
      }
LAB_0005c0fa:
      ssl3_send_alert(param_1,2,uVar6);
      iVar9 = 0;
      goto LAB_0005c104;
    }
  }
  else {
    pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
    uVar2 = EVP_MD_size(pEVar1);
    if (0x40 < uVar2) {
      OpenSSLDie("d1_pkt.c",0x1ba,"mac_size <= EVP_MAX_MD_SIZE");
    }
    uVar13 = *(int *)(iVar10 + 0x110) + (*(uint *)(iVar10 + 0x10c) >> 8);
    if ((uVar13 < uVar2) ||
       ((uVar3 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)), (uVar3 & 0xf0007) == 2
        && (uVar13 < uVar2 + 1)))) {
      ERR_put_error(0x14,0x101,0xa0,"d1_pkt.c",0x1ca);
      uVar6 = 0x32;
      goto LAB_0005c0fa;
    }
    uVar3 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
    if ((uVar3 & 0xf0007) == 2) {
      b = auStack_6c;
      ssl3_cbc_copy_mac(b,iVar10 + 0x10c,uVar2,uVar13);
      uVar13 = 0;
      *(uint *)(iVar10 + 0x110) = *(int *)(iVar10 + 0x110) - uVar2;
    }
    else {
      iVar11 = *(int *)(iVar10 + 0x110) - uVar2;
      *(int *)(iVar10 + 0x110) = iVar11;
      b = (undefined *)(*(int *)(iVar10 + 0x118) + iVar11);
      if (b == (undefined *)0x0) {
        uVar13 = 1;
      }
      else {
        uVar13 = 0;
      }
    }
    uVar4 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 4))(param_1,auStack_ac,0);
    if ((uVar13 | uVar4 >> 0x1f) == 0) {
      iVar11 = CRYPTO_memcmp(auStack_ac,b,uVar2);
      if (iVar11 != 0) {
        iVar9 = -1;
      }
    }
    else {
      iVar9 = -1;
    }
    if (*(uint *)(iVar10 + 0x110) <= uVar2 + 0x4400) goto LAB_0005c1e6;
  }
  iVar9 = 0;
  *(undefined4 *)(iVar10 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
LAB_0005c104:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar9);
}

