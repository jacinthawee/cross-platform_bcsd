
int a2d_ASN1_OBJECT(uchar *out,int olen,char *buf,int num)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  ulong uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint w;
  uint uVar10;
  byte *pbVar11;
  BIGNUM *a;
  uint w_00;
  int iVar12;
  int iVar13;
  int iVar14;
  int local_68;
  uchar *local_64;
  uchar *local_58;
  int local_50;
  uchar auStack_44 [24];
  int local_2c;
  
  local_2c = __stack_chk_guard;
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
        ERR_put_error(0xd,100,0x8a,"a_object.c",0x71);
      }
      else {
        iVar14 = num - 2;
        pbVar11 = (byte *)(buf + 2);
        if (iVar14 == 0) goto LAB_000afd6e;
        if (buf[1] == '.' || buf[1] == ' ') {
          local_68 = 0;
          a = (BIGNUM *)0x0;
          local_50 = 0x18;
          local_64 = auStack_44;
          do {
            w = 0;
            bVar2 = false;
            pbVar6 = pbVar11;
            do {
              while( true ) {
                pbVar11 = pbVar6 + 1;
                uVar10 = (uint)*pbVar6;
                iVar14 = iVar14 + -1;
                if (uVar10 == 0x20 || uVar10 == 0x2e) goto LAB_000afc90;
                w_00 = uVar10 - 0x30;
                if (9 < w_00) {
                  ERR_put_error(0xd,100,0x82,"a_object.c",0x87);
                  goto LAB_000afd56;
                }
                bVar3 = (bool)(bVar2 ^ 1);
                if (w < 0x19999991) {
                  bVar3 = false;
                }
                pbVar6 = pbVar11;
                if (!bVar3) break;
                if (((a == (BIGNUM *)0x0) && (a = BN_new(), a == (BIGNUM *)0x0)) ||
                   (iVar5 = BN_set_word(a,w), iVar5 == 0)) goto LAB_000afd56;
                bVar2 = true;
LAB_000afc74:
                iVar5 = BN_mul_word(a,10);
                if ((iVar5 == 0) || (iVar5 = BN_add_word(a,w_00), iVar5 == 0)) goto LAB_000afd56;
                if (iVar14 == 0) goto LAB_000afc90;
              }
              if (bVar2) goto LAB_000afc74;
              w = w_00 + w * 10;
            } while (iVar14 != 0);
LAB_000afc90:
            if (local_68 == 0) {
              if ((int)uVar4 < 2 && 0x27 < w) {
                ERR_put_error(0xd,100,0x93,"a_object.c",0x9b);
                goto LAB_000afd56;
              }
              if (bVar2) {
                iVar5 = BN_add_word(a,uVar4 * 0x28);
                if (iVar5 != 0) goto LAB_000afde0;
                goto LAB_000afd56;
              }
              w = w + uVar4 * 0x28;
LAB_000afcc0:
              iVar5 = 0;
              do {
                bVar1 = (byte)w;
                w = w >> 7;
                local_64[iVar5] = bVar1 & 0x7f;
                iVar12 = iVar5 + 1;
                iVar5 = iVar5 + 1;
              } while (w != 0);
            }
            else {
              if (!bVar2) goto LAB_000afcc0;
LAB_000afde0:
              iVar5 = BN_num_bits(a);
              iVar5 = (iVar5 + 6) / 7;
              if (local_50 < iVar5) {
                if (local_64 != auStack_44) {
                  CRYPTO_free(local_64);
                }
                local_50 = iVar5 + 0x20;
                local_64 = (uchar *)CRYPTO_malloc(local_50,"a_object.c",0xad);
                if (local_64 == (uchar *)0x0) goto LAB_000afd5e;
LAB_000afe24:
                iVar13 = 0;
                do {
                  uVar7 = BN_div_word(a,0x80);
                  if (uVar7 == 0xffffffff) goto LAB_000afd56;
                  iVar12 = iVar13 + 1;
                  local_64[iVar13] = (uchar)uVar7;
                  iVar13 = iVar12;
                } while (iVar12 != iVar5);
              }
              else {
                iVar12 = iVar5;
                if (iVar5 != 0) goto LAB_000afe24;
              }
            }
            if (out == (uchar *)0x0) {
              local_68 = local_68 + iVar12;
            }
            else {
              if (olen < local_68 + iVar12) {
                ERR_put_error(0xd,100,0x6b,"a_object.c",0xc3);
                goto LAB_000afd56;
              }
              if (1 < iVar12) {
                pbVar6 = local_64 + iVar12;
                pbVar8 = out + local_68;
                do {
                  pbVar6 = pbVar6 + -1;
                  pbVar9 = pbVar8 + 1;
                  *pbVar8 = *pbVar6 | 0x80;
                  pbVar8 = pbVar9;
                } while (pbVar9 != out + iVar12 + local_68 + -1);
                local_68 = local_68 + iVar12 + -1;
              }
              out[local_68] = *local_64;
              local_68 = local_68 + 1;
            }
            if (iVar14 == 0) {
              if (local_64 != auStack_44) {
                CRYPTO_free(local_64);
              }
              iVar14 = local_68;
              if (a != (BIGNUM *)0x0) {
                BN_free(a);
              }
              goto LAB_000afd6e;
            }
          } while (uVar10 == 0x20 || uVar10 == 0x2e);
        }
        else {
          local_64 = auStack_44;
          a = (BIGNUM *)0x0;
        }
        ERR_put_error(0xd,100,0x83,"a_object.c",0x7a);
LAB_000afd56:
        local_58 = auStack_44;
        if (local_64 != local_58) {
LAB_000afd5e:
          CRYPTO_free(local_64);
        }
        if (a != (BIGNUM *)0x0) {
          BN_free(a);
        }
      }
    }
    else {
      ERR_put_error(0xd,100,0x7a,"a_object.c",0x6c);
    }
  }
  iVar14 = 0;
LAB_000afd6e:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar14;
}

