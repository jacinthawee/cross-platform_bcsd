
undefined4 __regparm3 dtls1_process_record(int param_1,uint *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  EVP_MD *pEVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  int in_GS_OFFSET;
  bool bVar12;
  int iVar13;
  int iVar14;
  undefined *local_b4;
  undefined local_a0 [64];
  undefined local_60 [64];
  int local_20;
  
  iVar13 = *(int *)(param_1 + 0x58);
  iVar14 = *(int *)(param_1 + 0xc0);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = *(int *)(param_1 + 0x4c) + 0xd;
  *(int *)(iVar13 + 0x11c) = iVar2;
  if (*(uint *)(iVar13 + 0x110) < 0x4541) {
    *(int *)(iVar13 + 0x118) = iVar2;
    iVar2 = (***(code ***)(*(int *)(param_1 + 8) + 100))(param_1,0);
    if (iVar2 != 0) {
      if (((iVar14 != 0) && (*(int *)(param_1 + 0x80) != 0)) &&
         (pEVar4 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84)), pEVar4 != (EVP_MD *)0x0)) {
        pEVar4 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
        uVar5 = EVP_MD_size(pEVar4);
        if (0x40 < uVar5) {
          OpenSSLDie("d1_pkt.c",0x201,"mac_size <= EVP_MAX_MD_SIZE");
        }
        uVar6 = (*(uint *)(iVar13 + 0x10c) >> 8) + *(int *)(iVar13 + 0x110);
        if ((uVar5 <= uVar6) &&
           ((uVar7 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)),
            (uVar7 & 0xf0007) != 2 || (uVar5 + 1 <= uVar6)))) {
          uVar7 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
          if ((uVar7 & 0xf0007) == 2) {
            local_b4 = local_60;
            ssl3_cbc_copy_mac(local_b4,iVar13 + 0x10c,uVar5,uVar6);
            *(int *)(iVar13 + 0x110) = *(int *)(iVar13 + 0x110) - uVar5;
            bVar12 = false;
          }
          else {
            iVar14 = *(int *)(iVar13 + 0x110) - uVar5;
            *(int *)(iVar13 + 0x110) = iVar14;
            local_b4 = (undefined *)(iVar14 + *(int *)(iVar13 + 0x118));
            bVar12 = local_b4 == (undefined *)0x0;
          }
          iVar14 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 4))(param_1,local_a0,0);
          if (((iVar14 < 0) || (bVar12)) ||
             (iVar14 = CRYPTO_memcmp(local_a0,local_b4,uVar5), iVar14 != 0)) {
            iVar2 = -1;
          }
          if (uVar5 + 0x4400 <= *(uint *)(iVar13 + 0x110) &&
              *(uint *)(iVar13 + 0x110) != uVar5 + 0x4400) goto LAB_080b5960;
          goto LAB_080b5980;
        }
        ERR_put_error(0x14,0x101,0xa0,"d1_pkt.c",0x213);
        uVar3 = 0x32;
        goto LAB_080b57d4;
      }
LAB_080b5980:
      if (-1 < iVar2) {
        if (*(int *)(param_1 + 0x88) != 0) {
          if (0x4400 < *(uint *)(iVar13 + 0x110)) {
            iVar14 = 0x23f;
            iVar13 = 0x8c;
            goto LAB_080b57c0;
          }
          iVar14 = ssl3_do_uncompress(param_1);
          if (iVar14 == 0) {
            ERR_put_error(0x14,0x101,0x6b,"d1_pkt.c",0x244);
            uVar3 = 0x1e;
            goto LAB_080b57d4;
          }
        }
        if (*(uint *)(iVar13 + 0x110) < 0x4001) {
          iVar14 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(iVar13 + 0x114) = 0;
          *(undefined4 *)(param_1 + 0x50) = 0;
          uVar5 = (uint)*(byte *)(iVar14 + 0xf) - (uint)*(byte *)((int)param_2 + 0xb);
          iVar11 = ((uint)*(byte *)(iVar14 + 0xe) - (uint)*(byte *)((int)param_2 + 10)) +
                   ((int)uVar5 >> 8);
          iVar13 = ((uint)*(byte *)(iVar14 + 0xd) - (uint)*(byte *)((int)param_2 + 9)) +
                   (iVar11 >> 8);
          iVar2 = iVar13 >> 8;
          bVar10 = (byte)iVar11;
          bVar1 = (byte)iVar13;
          if ((uVar5 & 0x80) == 0) {
            iVar2 = iVar2 + ((uint)*(byte *)(iVar14 + 0xc) - (uint)*(byte *)(param_2 + 2));
            iVar11 = (iVar2 >> 8) +
                     ((uint)*(byte *)(iVar14 + 0xb) - (uint)*(byte *)((int)param_2 + 7));
            iVar8 = (iVar11 >> 8) +
                    ((uint)*(byte *)(iVar14 + 10) - (uint)*(byte *)((int)param_2 + 6));
            iVar9 = (iVar8 >> 8) + ((uint)*(byte *)(iVar14 + 9) - (uint)*(byte *)((int)param_2 + 5))
            ;
            iVar13 = (iVar9 >> 8) + ((uint)*(byte *)(iVar14 + 8) - (uint)*(byte *)(param_2 + 1));
            bVar10 = bVar10 | bVar1 | (byte)iVar2 | (byte)iVar11 | (byte)iVar8 | (byte)iVar9 |
                     (byte)iVar13;
          }
          else {
            iVar2 = iVar2 + ((uint)*(byte *)(iVar14 + 0xc) - (uint)*(byte *)(param_2 + 2));
            iVar11 = (iVar2 >> 8) +
                     ((uint)*(byte *)(iVar14 + 0xb) - (uint)*(byte *)((int)param_2 + 7));
            iVar8 = (iVar11 >> 8) +
                    ((uint)*(byte *)(iVar14 + 10) - (uint)*(byte *)((int)param_2 + 6));
            iVar9 = (iVar8 >> 8) + ((uint)*(byte *)(iVar14 + 9) - (uint)*(byte *)((int)param_2 + 5))
            ;
            iVar13 = (iVar9 >> 8) + ((uint)*(byte *)(iVar14 + 8) - (uint)*(byte *)(param_2 + 1));
            bVar10 = ~(bVar10 & bVar1 & (byte)iVar2 & (byte)iVar11 & (byte)iVar8 & (byte)iVar9 &
                      (byte)iVar13);
          }
          uVar5 = (uVar5 & 0xff) + (iVar13 >> 8) * 0x100;
          if (bVar10 != 0) {
            uVar5 = (iVar13 >> 8) << 8 | 0x80;
          }
          if ((int)uVar5 < 1) {
            uVar3 = 1;
            if (uVar5 == 0xffffffe1 || (int)-uVar5 < 0x1f) {
              *param_2 = *param_2 | 1 << ((byte)-uVar5 & 0x1f);
            }
          }
          else {
            if ((int)uVar5 < 0x20) {
              *param_2 = *param_2 << ((byte)uVar5 & 0x1f) | 1;
            }
            else {
              *param_2 = 1;
            }
            uVar5 = *(uint *)(iVar14 + 0xc);
            param_2[1] = *(uint *)(iVar14 + 8);
            param_2[2] = uVar5;
            uVar3 = 1;
          }
          goto LAB_080b57e5;
        }
        iVar14 = 0x24b;
        iVar13 = 0x92;
        goto LAB_080b57c0;
      }
    }
LAB_080b5960:
    *(undefined4 *)(iVar13 + 0x110) = 0;
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    iVar14 = 0x1dc;
    iVar13 = 0x96;
LAB_080b57c0:
    ERR_put_error(0x14,0x101,iVar13,"d1_pkt.c",iVar14);
    uVar3 = 0x16;
LAB_080b57d4:
    ssl3_send_alert(param_1,2,uVar3);
    uVar3 = 0;
  }
LAB_080b57e5:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

