
int a2d_ASN1_OBJECT(uchar *out,int olen,char *buf,int num)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  uint w;
  uint uVar8;
  byte *pbVar9;
  char *pcVar10;
  int iVar12;
  int iVar13;
  int in_GS_OFFSET;
  BIGNUM *local_68;
  uchar *local_5c;
  int local_54;
  uchar *local_4c;
  int local_44;
  uchar local_38 [24];
  int local_20;
  char *pcVar11;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (num != 0) {
    if (num == -1) {
      num = strlen(buf);
      cVar1 = *buf;
    }
    else {
      cVar1 = *buf;
    }
    uVar3 = (int)cVar1 - 0x30;
    if (uVar3 < 3) {
      if (num < 2) {
        ERR_put_error(0xd,100,0x8a,"a_object.c",0x71);
      }
      else {
        iVar4 = num - 2;
        pcVar10 = buf + 2;
        if (iVar4 != 0) {
          if ((buf[1] == ' ') || (buf[1] == '.')) {
            local_44 = 0x18;
            local_54 = 0;
            local_68 = (BIGNUM *)0x0;
            local_5c = local_38;
            do {
              w = 0;
              bVar2 = false;
              pcVar11 = pcVar10;
              do {
                while( true ) {
                  pcVar10 = pcVar11 + 1;
                  iVar12 = (int)*pcVar11;
                  iVar4 = iVar4 + -1;
                  if ((iVar12 == 0x20) || (iVar12 == 0x2e)) goto LAB_08135ba8;
                  uVar8 = iVar12 - 0x30;
                  if (9 < uVar8) {
                    ERR_put_error(0xd,100,0x82,"a_object.c",0x87);
                    goto LAB_08135cb0;
                  }
                  pcVar11 = pcVar10;
                  if ((bVar2) || (w < 0x19999991)) break;
                  if ((local_68 == (BIGNUM *)0x0) &&
                     (local_68 = BN_new(), local_68 == (BIGNUM *)0x0)) {
                    if (local_5c != local_38) goto LAB_08135cba;
                    goto LAB_08135cdd;
                  }
                  iVar5 = BN_set_word(local_68,w);
                  if (iVar5 == 0) goto LAB_08135cb0;
                  bVar2 = true;
LAB_08135b2d:
                  iVar5 = BN_mul_word(local_68,10);
                  if ((iVar5 == 0) || (iVar5 = BN_add_word(local_68,uVar8), iVar5 == 0))
                  goto LAB_08135cb0;
                  if (iVar4 == 0) goto LAB_08135ba8;
                }
                if (bVar2) goto LAB_08135b2d;
                w = uVar8 + w * 10;
              } while (iVar4 != 0);
LAB_08135ba8:
              if (local_54 == 0) {
                if (((int)uVar3 < 2) && (0x27 < w)) {
                  ERR_put_error(0xd,100,0x93,"a_object.c",0x9b);
                  goto LAB_08135cb0;
                }
                w = w + uVar3 * 0x28;
                if (!bVar2) goto LAB_08135bd0;
                iVar5 = BN_add_word(local_68,uVar3 * 0x28);
                if (iVar5 == 0) goto LAB_08135cb0;
LAB_08135d78:
                iVar5 = BN_num_bits(local_68);
                iVar5 = (iVar5 + 6) / 7;
                if (local_44 < iVar5) {
                  if (local_5c != local_38) {
                    CRYPTO_free(local_5c);
                  }
                  local_44 = iVar5 + 0x20;
                  local_5c = (uchar *)CRYPTO_malloc(local_44,"a_object.c",0xad);
                  if (local_5c == (uchar *)0x0) goto LAB_08135cba;
LAB_08135de7:
                  iVar13 = 0;
                  do {
                    uVar6 = BN_div_word(local_68,0x80);
                    if (uVar6 == 0xffffffff) goto LAB_08135cb0;
                    iVar7 = iVar13 + 1;
                    local_5c[iVar13] = (uchar)uVar6;
                    iVar13 = iVar7;
                  } while (iVar7 != iVar5);
                }
                else {
                  if (iVar5 != 0) goto LAB_08135de7;
                  iVar7 = 0;
                }
              }
              else {
                if (bVar2) goto LAB_08135d78;
LAB_08135bd0:
                iVar5 = 0;
                do {
                  uVar8 = w >> 7;
                  iVar7 = iVar5 + 1;
                  local_5c[iVar5] = (byte)w & 0x7f;
                  iVar5 = iVar7;
                  w = uVar8;
                } while (uVar8 != 0);
              }
              if (out == (uchar *)0x0) {
                local_54 = local_54 + iVar7;
              }
              else {
                if (olen < local_54 + iVar7) {
                  ERR_put_error(0xd,100,0x6b,"a_object.c",0xc3);
                  goto LAB_08135cb0;
                }
                iVar5 = iVar7 + -1;
                pbVar9 = out + local_54;
                if (0 < iVar5) {
                  do {
                    *pbVar9 = local_5c[iVar5] | 0x80;
                    iVar5 = iVar5 + -1;
                    pbVar9 = pbVar9 + 1;
                  } while (iVar5 != 0);
                  local_54 = iVar7 + -1 + local_54;
                }
                out[local_54] = *local_5c;
                local_54 = local_54 + 1;
              }
              if (iVar4 == 0) {
                if (local_5c != local_38) {
                  CRYPTO_free(local_5c);
                }
                if (local_68 != (BIGNUM *)0x0) {
                  BN_free(local_68);
                }
                goto LAB_08135cdf;
              }
            } while ((iVar12 == 0x2e) || (iVar12 == 0x20));
          }
          else {
            local_5c = local_38;
            local_68 = (BIGNUM *)0x0;
          }
          ERR_put_error(0xd,100,0x83,"a_object.c",0x7a);
LAB_08135cb0:
          local_4c = local_38;
          if (local_5c != local_4c) {
LAB_08135cba:
            CRYPTO_free(local_5c);
          }
          if (local_68 != (BIGNUM *)0x0) {
            BN_free(local_68);
          }
        }
      }
    }
    else {
      ERR_put_error(0xd,100,0x7a,"a_object.c",0x6c);
    }
  }
LAB_08135cdd:
  local_54 = 0;
LAB_08135cdf:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_54;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

