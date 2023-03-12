
int a2d_ASN1_OBJECT(uchar *out,int olen,char *buf,int num)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint w;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  BIGNUM *a;
  uint w_00;
  int iVar13;
  int local_6c;
  uchar *local_64;
  uchar *local_58;
  int local_50;
  uchar auStack_44 [24];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (num != 0) {
    if (num == -1) {
      num = strlen(buf);
      bVar1 = *buf;
    }
    else {
      bVar1 = *buf;
    }
    uVar4 = bVar1 - 0x30;
    if (uVar4 < 3) {
      if (num < 2) {
        ERR_put_error(0xd,100,0x8a,"a_object.c",0x73);
      }
      else {
        iVar13 = num - 2;
        pbVar12 = (byte *)(buf + 2);
        if (iVar13 == 0) goto LAB_000b2892;
        if (buf[1] == '.' || buf[1] == ' ') {
          local_6c = 0;
          a = (BIGNUM *)0x0;
          local_50 = 0x18;
          local_64 = auStack_44;
          do {
            w = 0;
            bVar2 = false;
            pbVar7 = pbVar12;
            do {
              while( true ) {
                pbVar12 = pbVar7 + 1;
                uVar11 = (uint)*pbVar7;
                iVar13 = iVar13 + -1;
                if (uVar11 == 0x20 || uVar11 == 0x2e) goto LAB_000b27ac;
                w_00 = uVar11 - 0x30;
                if (9 < w_00) {
                  ERR_put_error(0xd,100,0x82,"a_object.c",0x8b);
                  goto LAB_000b287a;
                }
                bVar3 = (bool)(bVar2 ^ 1);
                if (w < 0x19999991) {
                  bVar3 = false;
                }
                pbVar7 = pbVar12;
                if (!bVar3) break;
                if (((a == (BIGNUM *)0x0) && (a = BN_new(), a == (BIGNUM *)0x0)) ||
                   (iVar5 = BN_set_word(a,w), iVar5 == 0)) goto LAB_000b287a;
                bVar2 = true;
LAB_000b2790:
                iVar5 = BN_mul_word(a,10);
                if ((iVar5 == 0) || (iVar5 = BN_add_word(a,w_00), iVar5 == 0)) goto LAB_000b287a;
                if (iVar13 == 0) goto LAB_000b27ac;
              }
              if (bVar2) goto LAB_000b2790;
              w = w_00 + w * 10;
            } while (iVar13 != 0);
LAB_000b27ac:
            if (local_6c == 0) {
              if ((int)uVar4 < 2 && 0x27 < w) {
                ERR_put_error(0xd,100,0x93,"a_object.c",0xa3);
                goto LAB_000b287a;
              }
              if (bVar2) {
                iVar5 = BN_add_word(a,uVar4 * 0x28);
                if (iVar5 != 0) goto LAB_000b2904;
                goto LAB_000b287a;
              }
              w = w + uVar4 * 0x28;
LAB_000b27dc:
              iVar10 = 0;
              do {
                iVar5 = iVar10 + 1;
                bVar1 = (byte)w;
                w = w >> 7;
                local_64[iVar10] = bVar1 & 0x7f;
                iVar10 = iVar5;
              } while (w != 0);
            }
            else {
              if (!bVar2) goto LAB_000b27dc;
LAB_000b2904:
              iVar5 = BN_num_bits(a);
              iVar5 = (iVar5 + 6) / 7;
              if (local_50 < iVar5) {
                if (local_64 != auStack_44) {
                  CRYPTO_free(local_64);
                }
                local_50 = iVar5 + 0x20;
                local_64 = (uchar *)CRYPTO_malloc(local_50,"a_object.c",0xb9);
                if (local_64 == (uchar *)0x0) goto LAB_000b2882;
LAB_000b294a:
                iVar10 = 0;
                do {
                  uVar6 = BN_div_word(a,0x80);
                  local_64[iVar10] = (uchar)uVar6;
                  iVar10 = iVar10 + 1;
                } while (iVar5 != iVar10);
              }
              else if (iVar5 != 0) goto LAB_000b294a;
            }
            if (out == (uchar *)0x0) {
              local_6c = local_6c + iVar5;
            }
            else {
              if (olen < local_6c + iVar5) {
                ERR_put_error(0xd,100,0x6b,"a_object.c",0xcf);
                goto LAB_000b287a;
              }
              if (1 < iVar5) {
                pbVar7 = local_64 + iVar5;
                pbVar8 = out + local_6c;
                do {
                  pbVar7 = pbVar7 + -1;
                  pbVar9 = pbVar8 + 1;
                  *pbVar8 = *pbVar7 | 0x80;
                  pbVar8 = pbVar9;
                } while (pbVar9 != out + iVar5 + local_6c + -1);
                local_6c = local_6c + iVar5 + -1;
              }
              out[local_6c] = *local_64;
              local_6c = local_6c + 1;
            }
            if (iVar13 == 0) {
              if (local_64 != auStack_44) {
                CRYPTO_free(local_64);
              }
              iVar13 = local_6c;
              if (a != (BIGNUM *)0x0) {
                BN_free(a);
              }
              goto LAB_000b2892;
            }
          } while (uVar11 == 0x20 || uVar11 == 0x2e);
        }
        else {
          local_64 = auStack_44;
          a = (BIGNUM *)0x0;
        }
        ERR_put_error(0xd,100,0x83,"a_object.c",0x7d);
LAB_000b287a:
        local_58 = auStack_44;
        if (local_64 != local_58) {
LAB_000b2882:
          CRYPTO_free(local_64);
        }
        if (a != (BIGNUM *)0x0) {
          BN_free(a);
        }
      }
    }
    else {
      ERR_put_error(0xd,100,0x7a,"a_object.c",0x6d);
    }
  }
  iVar13 = 0;
LAB_000b2892:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar13;
}

