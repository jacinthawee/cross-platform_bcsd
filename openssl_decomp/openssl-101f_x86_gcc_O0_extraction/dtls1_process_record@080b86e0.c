
undefined4 __regparm3 dtls1_process_record(int param_1)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  EVP_MD *pEVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte bVar12;
  int iVar13;
  int in_GS_OFFSET;
  bool bVar14;
  int iVar15;
  int iVar16;
  undefined *local_b4;
  undefined local_a0 [64];
  undefined local_60 [64];
  int local_20;
  
  iVar15 = *(int *)(param_1 + 0x58);
  iVar16 = *(int *)(param_1 + 0xc0);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = *(int *)(param_1 + 0x4c) + 0xd;
  *(int *)(iVar15 + 0x11c) = iVar3;
  if (*(uint *)(iVar15 + 0x110) < 0x4541) {
    *(int *)(iVar15 + 0x118) = iVar3;
    iVar3 = (***(code ***)(*(int *)(param_1 + 8) + 100))(param_1,0);
    if (iVar3 != 0) {
      if (((iVar16 != 0) && (*(int *)(param_1 + 0x80) != 0)) &&
         (pEVar5 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84)), pEVar5 != (EVP_MD *)0x0)) {
        pEVar5 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
        uVar6 = EVP_MD_size(pEVar5);
        if (0x40 < uVar6) {
          OpenSSLDie("d1_pkt.c",0x1ba,"mac_size <= EVP_MAX_MD_SIZE");
        }
        uVar7 = (*(uint *)(iVar15 + 0x10c) >> 8) + *(int *)(iVar15 + 0x110);
        if ((uVar6 <= uVar7) &&
           ((uVar8 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)),
            (uVar8 & 0xf0007) != 2 || (uVar6 + 1 <= uVar7)))) {
          uVar8 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
          if ((uVar8 & 0xf0007) == 2) {
            local_b4 = local_60;
            ssl3_cbc_copy_mac(local_b4,iVar15 + 0x10c,uVar6,uVar7);
            *(int *)(iVar15 + 0x110) = *(int *)(iVar15 + 0x110) - uVar6;
            bVar14 = false;
          }
          else {
            iVar16 = *(int *)(iVar15 + 0x110) - uVar6;
            *(int *)(iVar15 + 0x110) = iVar16;
            local_b4 = (undefined *)(iVar16 + *(int *)(iVar15 + 0x118));
            bVar14 = local_b4 == (undefined *)0x0;
          }
          iVar16 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 4))(param_1,local_a0,0);
          if (((iVar16 < 0) || (bVar14)) ||
             (iVar16 = CRYPTO_memcmp(local_a0,local_b4,uVar6), iVar16 != 0)) {
            iVar3 = -1;
          }
          if (uVar6 + 0x4400 <= *(uint *)(iVar15 + 0x110) &&
              *(uint *)(iVar15 + 0x110) != uVar6 + 0x4400) goto LAB_080b88b0;
          goto LAB_080b88d0;
        }
        ERR_put_error(0x14,0x101,0xa0,"d1_pkt.c",0x1ca);
        uVar4 = 0x32;
        goto LAB_080b8742;
      }
LAB_080b88d0:
      if (-1 < iVar3) {
        if (*(int *)(param_1 + 0x88) != 0) {
          if (0x4400 < *(uint *)(iVar15 + 0x110)) {
            iVar16 = 0x1f7;
            iVar15 = 0x8c;
            goto LAB_080b872e;
          }
          iVar16 = ssl3_do_uncompress(param_1);
          if (iVar16 == 0) {
            ERR_put_error(0x14,0x101,0x6b,"d1_pkt.c",0x1fd);
            uVar4 = 0x1e;
            goto LAB_080b8742;
          }
        }
        if (*(uint *)(iVar15 + 0x110) < 0x4001) {
          *(undefined4 *)(iVar15 + 0x114) = 0;
          iVar15 = *(int *)(param_1 + 0x5c);
          *(undefined4 *)(param_1 + 0x50) = 0;
          iVar16 = *(int *)(param_1 + 0x58);
          uVar6 = (uint)*(byte *)(iVar16 + 0xf) - (uint)*(byte *)(iVar15 + 0x217);
          iVar13 = ((uint)*(byte *)(iVar16 + 0xe) - (uint)*(byte *)(iVar15 + 0x216)) +
                   ((int)uVar6 >> 8);
          iVar3 = ((uint)*(byte *)(iVar16 + 0xd) - (uint)*(byte *)(iVar15 + 0x215)) + (iVar13 >> 8);
          iVar9 = iVar3 >> 8;
          bVar12 = (byte)iVar13;
          bVar2 = (byte)iVar3;
          if ((uVar6 & 0x80) == 0) {
            iVar9 = iVar9 + ((uint)*(byte *)(iVar16 + 0xc) - (uint)*(byte *)(iVar15 + 0x214));
            iVar13 = (iVar9 >> 8) +
                     ((uint)*(byte *)(iVar16 + 0xb) - (uint)*(byte *)(iVar15 + 0x213));
            iVar10 = (iVar13 >> 8) +
                     ((uint)*(byte *)(iVar16 + 10) - (uint)*(byte *)(iVar15 + 0x212));
            iVar11 = (iVar10 >> 8) + ((uint)*(byte *)(iVar16 + 9) - (uint)*(byte *)(iVar15 + 0x211))
            ;
            iVar3 = (iVar11 >> 8) + ((uint)*(byte *)(iVar16 + 8) - (uint)*(byte *)(iVar15 + 0x210));
            bVar12 = bVar12 | bVar2 | (byte)iVar9 | (byte)iVar13 | (byte)iVar10 | (byte)iVar11 |
                     (byte)iVar3;
          }
          else {
            iVar9 = iVar9 + ((uint)*(byte *)(iVar16 + 0xc) - (uint)*(byte *)(iVar15 + 0x214));
            iVar13 = (iVar9 >> 8) +
                     ((uint)*(byte *)(iVar16 + 0xb) - (uint)*(byte *)(iVar15 + 0x213));
            iVar10 = (iVar13 >> 8) +
                     ((uint)*(byte *)(iVar16 + 10) - (uint)*(byte *)(iVar15 + 0x212));
            iVar11 = (iVar10 >> 8) + ((uint)*(byte *)(iVar16 + 9) - (uint)*(byte *)(iVar15 + 0x211))
            ;
            iVar3 = (iVar11 >> 8) + ((uint)*(byte *)(iVar16 + 8) - (uint)*(byte *)(iVar15 + 0x210));
            bVar12 = ~(bVar12 & bVar2 & (byte)iVar9 & (byte)iVar13 & (byte)iVar10 & (byte)iVar11 &
                      (byte)iVar3);
          }
          uVar6 = (uVar6 & 0xff) + (iVar3 >> 8) * 0x100;
          if (bVar12 != 0) {
            uVar6 = (iVar3 >> 8) << 8 | 0x80;
          }
          if ((int)uVar6 < 1) {
            uVar4 = 1;
            if (uVar6 == 0xffffffe1 || (int)-uVar6 < 0x1f) {
              *(uint *)(iVar15 + 0x20c) = *(uint *)(iVar15 + 0x20c) | 1 << ((byte)-uVar6 & 0x1f);
            }
          }
          else {
            if ((int)uVar6 < 0x20) {
              *(uint *)(iVar15 + 0x20c) = *(int *)(iVar15 + 0x20c) << ((byte)uVar6 & 0x1f) | 1;
            }
            else {
              *(undefined4 *)(iVar15 + 0x20c) = 1;
            }
            uVar1 = *(undefined4 *)(iVar16 + 0xc);
            uVar4 = 1;
            *(undefined4 *)(iVar15 + 0x210) = *(undefined4 *)(iVar16 + 8);
            *(undefined4 *)(iVar15 + 0x214) = uVar1;
          }
          goto LAB_080b8753;
        }
        iVar16 = 0x205;
        iVar15 = 0x92;
        goto LAB_080b872e;
      }
    }
LAB_080b88b0:
    *(undefined4 *)(iVar15 + 0x110) = 0;
    uVar4 = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    iVar16 = 0x197;
    iVar15 = 0x96;
LAB_080b872e:
    ERR_put_error(0x14,0x101,iVar15,"d1_pkt.c",iVar16);
    uVar4 = 0x16;
LAB_080b8742:
    ssl3_send_alert(param_1,2,uVar4);
    uVar4 = 0;
  }
LAB_080b8753:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

