
size_t b64_read(BIO *param_1,void *param_2,size_t param_3)

{
  byte *pbVar1;
  undefined4 *puVar2;
  EVP_ENCODE_CTX *ctx;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  byte *pbVar6;
  size_t sVar7;
  size_t *out;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  uchar *in;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *in_00;
  size_t sVar14;
  undefined4 *puVar15;
  size_t *outl;
  undefined4 *puVar16;
  uint uVar17;
  bool bVar18;
  undefined4 *local_4c;
  void *local_44;
  size_t local_40;
  size_t local_34;
  undefined4 *local_2c [2];
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  outl = (size_t *)param_1->ptr;
  if (outl == (size_t *)0x0) {
    return 0;
  }
  if (param_1->next_bio == (bio_st *)0x0) {
    return 0;
  }
  BIO_clear_flags(param_1,0xf);
  if (outl[4] != 2) {
    outl[4] = 2;
    *outl = 0;
    outl[1] = 0;
    outl[2] = 0;
    EVP_DecodeInit((EVP_ENCODE_CTX *)(outl + 7));
  }
  sVar7 = *outl;
  if ((int)sVar7 < 1) {
    local_40 = 0;
    local_44 = param_2;
  }
  else {
    sVar5 = outl[1];
    if ((int)sVar7 < (int)sVar5) {
      OpenSSLDie("bio_b64.c",0xa9,"ctx->buf_len >= ctx->buf_off");
      sVar7 = *outl;
      sVar5 = outl[1];
    }
    local_40 = sVar7 - sVar5;
    if ((int)param_3 <= (int)(sVar7 - sVar5)) {
      local_40 = param_3;
    }
    if (0x5dd < (int)(local_40 + sVar5)) {
      OpenSSLDie("bio_b64.c",0xac,"ctx->buf_off+i < (int)sizeof(ctx->buf)");
      sVar5 = outl[1];
    }
    memcpy(param_2,(void *)((int)outl + sVar5 + 0x7c),local_40);
    sVar7 = outl[1] + local_40;
    param_3 = param_3 - local_40;
    bVar18 = sVar7 == *outl;
    outl[1] = sVar7;
    local_44 = (void *)((int)param_2 + local_40);
    if (bVar18) {
      sVar7 = 0;
      *outl = 0;
    }
    if (bVar18) {
      outl[1] = sVar7;
    }
  }
  if ((int)param_3 < 1) {
    local_34 = 0;
  }
  else {
    if (0 < (int)outl[6]) {
      out = outl + 0x1f;
      ctx = (EVP_ENCODE_CTX *)(outl + 7);
      local_34 = 0;
LAB_000ae696:
      sVar7 = BIO_read(param_1->next_bio,(void *)((int)outl + outl[2] + 0x65a),0x400 - outl[2]);
      if ((int)sVar7 < 1) {
        sVar5 = BIO_test_flags(param_1->next_bio,8);
        local_34 = sVar7;
        if (sVar5 != 0) goto LAB_000ae764;
        sVar14 = outl[2];
        outl[6] = sVar7;
        if (sVar14 == 0) goto LAB_000ae764;
      }
      else {
        sVar14 = outl[2];
        sVar5 = sVar7;
      }
      puVar15 = (undefined4 *)(sVar14 + sVar5);
      outl[2] = (size_t)puVar15;
      if (outl[5] != 0) {
        uVar3 = BIO_test_flags(param_1,-1);
        if ((undefined4 *)(uVar3 & 0x100) != (undefined4 *)0x0) {
          outl[2] = 0;
          goto LAB_000ae6d0;
        }
        if (outl[5] == 0) goto LAB_000ae6c6;
        puVar13 = (undefined4 *)((int)outl + 0x65a);
        if (0 < (int)puVar15) {
          puVar16 = puVar13;
          puVar2 = (undefined4 *)(uVar3 & 0x100);
          in_00 = puVar13;
LAB_000ae7e6:
          do {
            puVar12 = puVar2;
            local_4c = (undefined4 *)((int)outl + 0x65a);
            puVar11 = (undefined4 *)((int)puVar16 + 1);
            puVar8 = (undefined4 *)(uint)*(byte *)puVar16;
            puVar16 = puVar11;
            if (puVar8 != (undefined4 *)0xa) goto LAB_000ae7de;
            puVar8 = (undefined4 *)outl[3];
            if (puVar8 == (undefined4 *)0x0) {
              puVar8 = in_00;
              iVar4 = EVP_DecodeUpdate(ctx,(uchar *)out,(int *)local_2c,(uchar *)in_00,
                                       (int)puVar11 - (int)in_00);
              if (((iVar4 < 1) && (puVar8 = local_2c[0], local_2c[0] == (undefined4 *)0x0)) &&
                 (puVar8 = (undefined4 *)outl[5], puVar8 != (undefined4 *)0x0)) {
                EVP_DecodeInit(ctx);
                in_00 = puVar11;
                goto LAB_000ae7de;
              }
              if (local_4c != in_00) {
                puVar8 = (undefined4 *)((int)local_4c - (int)in_00);
                puVar15 = (undefined4 *)((int)puVar15 + (int)puVar8);
                if (0 < (int)puVar15) {
                  puVar8 = (undefined4 *)
                           (uint)((undefined4 *)((int)outl + 0x662) <= in_00 ||
                                 in_00 + 2 <= local_4c);
                  if (puVar15 < (undefined4 *)0xb) {
                    puVar8 = (undefined4 *)0x0;
                  }
                  if ((((uint)local_4c | (uint)in_00) & 7) != 0) {
                    puVar8 = (undefined4 *)0x0;
                  }
                  if (puVar8 == (undefined4 *)0x0) {
                    do {
                      pbVar1 = (byte *)((int)in_00 + (int)puVar8);
                      pbVar6 = (byte *)((int)outl + (int)puVar8);
                      puVar8 = (undefined4 *)((int)puVar8 + 1);
                      pbVar6[0x65a] = *pbVar1;
                    } while (puVar8 != puVar15);
                  }
                  else {
                    uVar3 = 0;
                    puVar16 = (undefined4 *)((uint)puVar15 & 0xfffffff8);
                    puVar13 = in_00 + -2;
                    do {
                      puVar8 = (undefined4 *)puVar13[3];
                      uVar3 = uVar3 + 1;
                      *local_4c = puVar13[2];
                      local_4c[1] = puVar8;
                      local_4c = local_4c + 2;
                      puVar13 = puVar13 + 2;
                    } while (uVar3 < (uint)puVar15 >> 3);
                    if (puVar15 != puVar16) {
                      puVar8 = (undefined4 *)((int)puVar16 + 1);
                      ((byte *)((int)outl + (int)puVar16))[0x65a] =
                           *(byte *)((int)in_00 + ((uint)puVar15 & 0xfffffff8));
                      if ((int)puVar8 < (int)puVar15) {
                        pbVar1 = (byte *)((int)in_00 + (int)puVar8);
                        pbVar6 = (byte *)((int)outl + (int)puVar8);
                        puVar8 = (undefined4 *)((int)puVar16 + 2);
                        pbVar6[0x65a] = *pbVar1;
                        if ((int)puVar8 < (int)puVar15) {
                          pbVar1 = (byte *)((int)in_00 + (int)puVar8);
                          pbVar6 = (byte *)((int)outl + (int)puVar8);
                          puVar8 = (undefined4 *)((int)puVar16 + 3);
                          pbVar6[0x65a] = *pbVar1;
                          if ((int)puVar8 < (int)puVar15) {
                            pbVar1 = (byte *)((int)in_00 + (int)puVar8);
                            pbVar6 = (byte *)((int)outl + (int)puVar8);
                            puVar8 = puVar16 + 1;
                            pbVar6[0x65a] = *pbVar1;
                            if ((int)puVar8 < (int)puVar15) {
                              pbVar1 = (byte *)((int)in_00 + (int)puVar8);
                              pbVar6 = (byte *)((int)outl + (int)puVar8);
                              puVar8 = (undefined4 *)((int)puVar16 + 5);
                              pbVar6[0x65a] = *pbVar1;
                              if ((int)puVar8 < (int)puVar15) {
                                pbVar1 = (byte *)((int)in_00 + (int)puVar8);
                                pbVar6 = (byte *)((int)outl + (int)puVar8);
                                puVar8 = (undefined4 *)((int)puVar16 + 6);
                                pbVar6[0x65a] = *pbVar1;
                                if ((int)puVar8 < (int)puVar15) {
                                  pbVar1 = (byte *)((int)in_00 + (int)puVar8);
                                  puVar8 = (undefined4 *)((int)puVar8 + (int)outl);
                                  *(byte *)((int)puVar8 + 0x65a) = *pbVar1;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              EVP_DecodeInit(ctx);
              outl[5] = 0;
              goto LAB_000ae806;
            }
            outl[3] = 0;
            puVar2 = (undefined4 *)((int)puVar12 + 1);
            in_00 = puVar11;
          } while (puVar11 != (undefined4 *)((int)puVar13 + (int)puVar15));
          goto LAB_000ae802;
        }
        if (puVar15 == (undefined4 *)0x0) goto joined_r0x000ae68c;
        goto LAB_000ae80a;
      }
LAB_000ae6c6:
      if ((0x3ff < (int)puVar15) || ((int)outl[6] < 1)) goto LAB_000ae6d0;
      goto joined_r0x000ae68c;
    }
    local_34 = 0;
  }
LAB_000ae764:
  BIO_copy_next_retry(param_1);
  if (local_40 == 0) {
    local_40 = local_34;
  }
  return local_40;
LAB_000ae7de:
  puVar2 = (undefined4 *)((int)puVar12 + 1);
  if (puVar11 == (undefined4 *)((int)puVar13 + (int)puVar15)) goto LAB_000ae802;
  goto LAB_000ae7e6;
LAB_000ae802:
  puVar12 = (undefined4 *)((int)puVar12 + 1);
LAB_000ae806:
  local_4c = (undefined4 *)((int)outl + 0x65a);
  if (puVar12 == puVar15) {
    if (in_00 == local_4c) {
      if (puVar12 == (undefined4 *)0x400) {
        outl[2] = 0;
        puVar8 = (undefined4 *)0x1;
      }
      if (puVar12 == (undefined4 *)0x400) {
        outl[3] = (size_t)puVar8;
      }
    }
    else if (in_00 != puVar11) {
      uVar3 = (int)puVar11 - (int)in_00;
      if (0 < (int)uVar3) {
        uVar9 = (uint)((undefined4 *)((int)outl + 0x662) <= in_00 || in_00 + 2 <= local_4c);
        if (uVar3 < 0xb) {
          uVar9 = 0;
        }
        if ((((uint)local_4c | (uint)in_00) & 7) != 0) {
          uVar9 = 0;
        }
        if (uVar9 == 0) {
          do {
            uVar17 = uVar9 + 1;
            *(byte *)((int)outl + uVar9 + 0x65a) = *(byte *)((int)in_00 + uVar9);
            uVar9 = uVar17;
          } while (uVar17 != uVar3);
        }
        else {
          uVar9 = 0;
          uVar17 = uVar3 & 0xfffffff8;
          puVar15 = in_00 + -2;
          do {
            uVar10 = puVar15[3];
            uVar9 = uVar9 + 1;
            *local_4c = puVar15[2];
            local_4c[1] = uVar10;
            local_4c = local_4c + 2;
            puVar15 = puVar15 + 2;
          } while (uVar9 < uVar3 >> 3);
          if (uVar17 != uVar3) {
            *(byte *)((int)outl + uVar17 + 0x65a) = *(byte *)((int)in_00 + (uVar3 & 0xfffffff8));
            if ((int)(uVar17 + 1) < (int)uVar3) {
              *(byte *)((int)outl + uVar17 + 0x65b) = *(byte *)((int)in_00 + uVar17 + 1);
              if ((int)(uVar17 + 2) < (int)uVar3) {
                *(byte *)((int)outl + uVar17 + 0x65c) = *(byte *)((int)in_00 + uVar17 + 2);
                if ((int)(uVar17 + 3) < (int)uVar3) {
                  *(byte *)((int)outl + uVar17 + 0x65d) = *(byte *)((int)in_00 + uVar17 + 3);
                  if ((int)(uVar17 + 4) < (int)uVar3) {
                    *(byte *)((int)outl + uVar17 + 0x65e) = *(byte *)((int)in_00 + uVar17 + 4);
                    if ((int)(uVar17 + 5) < (int)uVar3) {
                      *(byte *)((int)outl + uVar17 + 0x65f) = *(byte *)((int)in_00 + uVar17 + 5);
                      if ((int)(uVar17 + 6) < (int)uVar3) {
                        *(byte *)((int)outl + uVar17 + 0x660) = *(byte *)((int)in_00 + uVar17 + 6);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      outl[2] = uVar3;
    }
    goto joined_r0x000ae68c;
  }
LAB_000ae80a:
  outl[2] = 0;
LAB_000ae6d0:
  in = (uchar *)((int)outl + 0x65a);
  uVar3 = BIO_test_flags(param_1,-1);
  if ((uVar3 & 0x100) == 0) {
    sVar7 = EVP_DecodeUpdate(ctx,(uchar *)out,(int *)outl,in,(int)puVar15);
    outl[2] = 0;
LAB_000ae78e:
    outl[1] = 0;
    if ((int)sVar7 < 0) {
      *outl = 0;
      local_34 = 0;
      goto LAB_000ae764;
    }
    sVar7 = *outl;
  }
  else {
    puVar13 = (undefined4 *)((uint)puVar15 & 0xfffffffc);
    sVar7 = EVP_DecodeBlock((uchar *)out,in,(int)puVar13);
    if ((2 < (int)puVar13) && (((byte *)((int)outl + (int)puVar13))[0x659] == 0x3d)) {
      if (((byte *)((int)outl + (int)puVar13))[0x658] == 0x3d) {
        sVar7 = sVar7 - 2;
      }
      else {
        sVar7 = sVar7 - 1;
      }
    }
    if (puVar13 != puVar15) {
      memmove(in,(byte *)((int)outl + (int)puVar13) + 0x65a,(int)puVar15 - (int)puVar13);
      outl[2] = (int)puVar15 - (int)puVar13;
    }
    if ((int)sVar7 < 1) {
      *outl = 0;
      goto LAB_000ae78e;
    }
    *outl = sVar7;
    outl[1] = 0;
  }
  if ((int)param_3 <= (int)sVar7) {
    sVar7 = param_3;
  }
  local_40 = local_40 + sVar7;
  param_3 = param_3 - sVar7;
  memcpy(local_44,out,sVar7);
  sVar5 = *outl;
  outl[1] = sVar7;
  if (sVar5 == sVar7) {
    *outl = 0;
  }
  if (sVar5 == sVar7) {
    outl[1] = 0;
  }
  local_44 = (void *)((int)local_44 + sVar7);
joined_r0x000ae68c:
  if (((int)param_3 < 1) || ((int)outl[6] < 1)) goto LAB_000ae764;
  goto LAB_000ae696;
}

