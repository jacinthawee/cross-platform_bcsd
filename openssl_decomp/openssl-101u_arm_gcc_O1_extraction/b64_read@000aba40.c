
size_t b64_read(BIO *param_1,void *param_2,size_t param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  byte *pbVar5;
  size_t sVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  size_t *out;
  EVP_ENCODE_CTX *ctx;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *in;
  size_t sVar14;
  undefined4 *puVar15;
  size_t *outl;
  uchar *in_00;
  undefined4 *puVar16;
  undefined4 *puVar17;
  bool bVar18;
  void *local_50;
  undefined4 *local_4c;
  size_t local_44;
  size_t local_38;
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
  sVar4 = *outl;
  if ((int)sVar4 < 1) {
    local_44 = 0;
    local_50 = param_2;
  }
  else {
    sVar6 = outl[1];
    if ((int)sVar4 < (int)sVar6) {
      OpenSSLDie("bio_b64.c",0xad,"ctx->buf_len >= ctx->buf_off");
      sVar4 = *outl;
      sVar6 = outl[1];
    }
    local_44 = sVar4 - sVar6;
    if ((int)param_3 <= (int)(sVar4 - sVar6)) {
      local_44 = param_3;
    }
    if (0x5dd < (int)(local_44 + sVar6)) {
      OpenSSLDie("bio_b64.c",0xb1,"ctx->buf_off + i < (int)sizeof(ctx->buf)");
      sVar6 = outl[1];
    }
    memcpy(param_2,(void *)((int)outl + sVar6 + 0x7c),local_44);
    sVar4 = outl[1] + local_44;
    param_3 = param_3 - local_44;
    bVar18 = sVar4 == *outl;
    outl[1] = sVar4;
    local_50 = (void *)((int)param_2 + local_44);
    if (bVar18) {
      sVar4 = 0;
      *outl = 0;
    }
    if (bVar18) {
      outl[1] = sVar4;
    }
  }
  if ((int)param_3 < 1) {
    local_38 = 0;
  }
  else {
    local_38 = 0;
    if (0 < (int)outl[6]) {
      out = outl + 0x1f;
      ctx = (EVP_ENCODE_CTX *)(outl + 7);
LAB_000abb34:
      sVar4 = BIO_read(param_1->next_bio,(void *)((int)outl + outl[2] + 0x65a),0x400 - outl[2]);
      if ((int)sVar4 < 1) {
        sVar6 = BIO_test_flags(param_1->next_bio,8);
        local_38 = sVar4;
        if (sVar6 != 0) goto LAB_000abc04;
        sVar14 = outl[2];
        outl[6] = sVar4;
        if (sVar14 == 0) goto LAB_000abc04;
      }
      else {
        sVar14 = outl[2];
        sVar6 = sVar4;
      }
      puVar15 = (undefined4 *)(sVar14 + sVar6);
      outl[2] = (size_t)puVar15;
      if (outl[5] != 0) {
        uVar2 = BIO_test_flags(param_1,-1);
        puVar12 = (undefined4 *)(uVar2 & 0x100);
        if (puVar12 != (undefined4 *)0x0) {
          outl[2] = 0;
          goto LAB_000abb6e;
        }
        puVar7 = (undefined4 *)outl[5];
        if (puVar7 == (undefined4 *)0x0) goto LAB_000abb64;
        puVar13 = (undefined4 *)((int)outl + 0x65a);
        in = puVar13;
        local_2c[0] = puVar12;
        if (0 < (int)puVar15) {
          puVar16 = (undefined4 *)((int)puVar13 + (int)puVar15);
          puVar11 = puVar13;
          puVar17 = puVar12;
LAB_000abc88:
          do {
            puVar12 = puVar17;
            local_4c = (undefined4 *)((int)outl + 0x65a);
            puVar13 = (undefined4 *)((int)puVar11 + 1);
            puVar7 = (undefined4 *)(uint)*(byte *)puVar11;
            puVar11 = puVar13;
            if (puVar7 != (undefined4 *)0xa) goto LAB_000abc80;
            puVar7 = (undefined4 *)outl[3];
            if (puVar7 == (undefined4 *)0x0) {
              puVar7 = in;
              iVar3 = EVP_DecodeUpdate(ctx,(uchar *)out,(int *)local_2c,(uchar *)in,
                                       (int)puVar13 - (int)in);
              if (((iVar3 < 1) && (puVar7 = local_2c[0], local_2c[0] == (undefined4 *)0x0)) &&
                 (puVar7 = (undefined4 *)outl[5], puVar7 != (undefined4 *)0x0)) {
                EVP_DecodeInit(ctx);
                in = puVar13;
                goto LAB_000abc80;
              }
              if (local_4c != in) {
                puVar7 = (undefined4 *)((int)local_4c - (int)in);
                puVar15 = (undefined4 *)((int)puVar15 + (int)puVar7);
                if (0 < (int)puVar15) {
                  puVar7 = (undefined4 *)
                           (uint)((undefined4 *)((int)outl + 0x662) <= in || in + 2 <= local_4c);
                  if (puVar15 < (undefined4 *)0xb) {
                    puVar7 = (undefined4 *)0x0;
                  }
                  if ((((uint)local_4c | (uint)in) & 7) != 0) {
                    puVar7 = (undefined4 *)0x0;
                  }
                  if (puVar7 == (undefined4 *)0x0) {
                    do {
                      pbVar1 = (byte *)((int)in + (int)puVar7);
                      pbVar5 = (byte *)((int)outl + (int)puVar7);
                      puVar7 = (undefined4 *)((int)puVar7 + 1);
                      pbVar5[0x65a] = *pbVar1;
                    } while (puVar7 != puVar15);
                  }
                  else {
                    uVar2 = 0;
                    puVar17 = (undefined4 *)((uint)puVar15 & 0xfffffff8);
                    puVar11 = in + -2;
                    do {
                      puVar7 = (undefined4 *)puVar11[3];
                      uVar2 = uVar2 + 1;
                      *local_4c = puVar11[2];
                      local_4c[1] = puVar7;
                      local_4c = local_4c + 2;
                      puVar11 = puVar11 + 2;
                    } while (uVar2 < (uint)puVar15 >> 3);
                    if (puVar15 != puVar17) {
                      puVar7 = (undefined4 *)((int)puVar17 + 1);
                      ((byte *)((int)outl + (int)puVar17))[0x65a] =
                           *(byte *)((int)in + ((uint)puVar15 & 0xfffffff8));
                      if ((int)puVar7 < (int)puVar15) {
                        pbVar1 = (byte *)((int)in + (int)puVar7);
                        pbVar5 = (byte *)((int)outl + (int)puVar7);
                        puVar7 = (undefined4 *)((int)puVar17 + 2);
                        pbVar5[0x65a] = *pbVar1;
                        if ((int)puVar7 < (int)puVar15) {
                          pbVar1 = (byte *)((int)in + (int)puVar7);
                          pbVar5 = (byte *)((int)outl + (int)puVar7);
                          puVar7 = (undefined4 *)((int)puVar17 + 3);
                          pbVar5[0x65a] = *pbVar1;
                          if ((int)puVar7 < (int)puVar15) {
                            pbVar1 = (byte *)((int)in + (int)puVar7);
                            pbVar5 = (byte *)((int)outl + (int)puVar7);
                            puVar7 = puVar17 + 1;
                            pbVar5[0x65a] = *pbVar1;
                            if ((int)puVar7 < (int)puVar15) {
                              pbVar1 = (byte *)((int)in + (int)puVar7);
                              pbVar5 = (byte *)((int)outl + (int)puVar7);
                              puVar7 = (undefined4 *)((int)puVar17 + 5);
                              pbVar5[0x65a] = *pbVar1;
                              if ((int)puVar7 < (int)puVar15) {
                                pbVar1 = (byte *)((int)in + (int)puVar7);
                                pbVar5 = (byte *)((int)outl + (int)puVar7);
                                puVar7 = (undefined4 *)((int)puVar17 + 6);
                                pbVar5[0x65a] = *pbVar1;
                                if ((int)puVar7 < (int)puVar15) {
                                  pbVar1 = (byte *)((int)in + (int)puVar7);
                                  puVar7 = (undefined4 *)((int)puVar7 + (int)outl);
                                  *(byte *)((int)puVar7 + 0x65a) = *pbVar1;
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
              goto LAB_000abca8;
            }
            outl[3] = 0;
            puVar17 = (undefined4 *)((int)puVar12 + 1);
            in = puVar13;
          } while (puVar13 != puVar16);
          goto LAB_000abca4;
        }
        goto LAB_000abca8;
      }
LAB_000abb64:
      if ((0x3ff < (int)puVar15) || ((int)outl[6] < 1)) goto LAB_000abb6e;
      goto joined_r0x000abb2a;
    }
  }
LAB_000abc04:
  BIO_copy_next_retry(param_1);
  if (local_44 == 0) {
    local_44 = local_38;
  }
  return local_44;
LAB_000abc80:
  puVar17 = (undefined4 *)((int)puVar12 + 1);
  if (puVar13 == puVar16) goto LAB_000abca4;
  goto LAB_000abc88;
LAB_000abca4:
  puVar12 = (undefined4 *)((int)puVar12 + 1);
LAB_000abca8:
  local_4c = (undefined4 *)((int)outl + 0x65a);
  if ((puVar12 == puVar15) && (local_2c[0] == (undefined4 *)0x0)) {
    if (in == local_4c) {
      if (puVar12 == (undefined4 *)0x400) {
        outl[2] = 0;
        puVar7 = (undefined4 *)0x1;
      }
      if (puVar12 == (undefined4 *)0x400) {
        outl[3] = (size_t)puVar7;
      }
    }
    else if (in != puVar13) {
      uVar2 = (int)puVar13 - (int)in;
      if (0 < (int)uVar2) {
        uVar8 = (uint)((undefined4 *)((int)outl + 0x662) <= in || in + 2 <= local_4c);
        if (uVar2 < 0xb) {
          uVar8 = 0;
        }
        if ((((uint)local_4c | (uint)in) & 7) != 0) {
          uVar8 = 0;
        }
        if (uVar8 == 0) {
          do {
            uVar10 = uVar8 + 1;
            *(byte *)((int)outl + uVar8 + 0x65a) = *(byte *)((int)in + uVar8);
            uVar8 = uVar10;
          } while (uVar10 != uVar2);
        }
        else {
          uVar8 = uVar2 & 0xfffffff8;
          puVar15 = in + -2;
          puVar12 = local_2c[0];
          do {
            uVar9 = puVar15[3];
            puVar12 = (undefined4 *)((int)puVar12 + 1);
            *local_4c = puVar15[2];
            local_4c[1] = uVar9;
            puVar15 = puVar15 + 2;
            local_4c = local_4c + 2;
          } while (puVar12 < (undefined4 *)(uVar2 >> 3));
          if (uVar8 != uVar2) {
            *(byte *)((int)outl + uVar8 + 0x65a) = *(byte *)((int)in + (uVar2 & 0xfffffff8));
            if ((int)(uVar8 + 1) < (int)uVar2) {
              *(byte *)((int)outl + uVar8 + 0x65b) = *(byte *)((int)in + uVar8 + 1);
              if ((int)(uVar8 + 2) < (int)uVar2) {
                *(byte *)((int)outl + uVar8 + 0x65c) = *(byte *)((int)in + uVar8 + 2);
                if ((int)(uVar8 + 3) < (int)uVar2) {
                  *(byte *)((int)outl + uVar8 + 0x65d) = *(byte *)((int)in + uVar8 + 3);
                  if ((int)(uVar8 + 4) < (int)uVar2) {
                    *(byte *)((int)outl + uVar8 + 0x65e) = *(byte *)((int)in + uVar8 + 4);
                    if ((int)(uVar8 + 5) < (int)uVar2) {
                      *(byte *)((int)outl + uVar8 + 0x65f) = *(byte *)((int)in + uVar8 + 5);
                      if ((int)(uVar8 + 6) < (int)uVar2) {
                        *(byte *)((int)outl + uVar8 + 0x660) = *(byte *)((int)in + uVar8 + 6);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      outl[2] = uVar2;
    }
    goto joined_r0x000abb2a;
  }
  outl[2] = 0;
LAB_000abb6e:
  in_00 = (uchar *)((int)outl + 0x65a);
  uVar2 = BIO_test_flags(param_1,-1);
  if ((uVar2 & 0x100) == 0) {
    sVar4 = EVP_DecodeUpdate(ctx,(uchar *)out,(int *)outl,in_00,(int)puVar15);
    outl[2] = 0;
LAB_000abc2e:
    outl[1] = 0;
    if ((int)sVar4 < 0) {
      *outl = 0;
      local_38 = 0;
      goto LAB_000abc04;
    }
    sVar4 = *outl;
  }
  else {
    puVar12 = (undefined4 *)((uint)puVar15 & 0xfffffffc);
    sVar4 = EVP_DecodeBlock((uchar *)out,in_00,(int)puVar12);
    if ((2 < (int)puVar12) && (((byte *)((int)outl + (int)puVar12))[0x659] == 0x3d)) {
      if (((byte *)((int)outl + (int)puVar12))[0x658] == 0x3d) {
        sVar4 = sVar4 - 2;
      }
      else {
        sVar4 = sVar4 - 1;
      }
    }
    if (puVar12 != puVar15) {
      memmove(in_00,(byte *)((int)outl + (int)puVar12) + 0x65a,(int)puVar15 - (int)puVar12);
      outl[2] = (int)puVar15 - (int)puVar12;
    }
    if ((int)sVar4 < 1) {
      *outl = 0;
      goto LAB_000abc2e;
    }
    *outl = sVar4;
    outl[1] = 0;
  }
  if ((int)param_3 <= (int)sVar4) {
    sVar4 = param_3;
  }
  local_44 = local_44 + sVar4;
  memcpy(local_50,out,sVar4);
  sVar6 = *outl;
  param_3 = param_3 - sVar4;
  outl[1] = sVar4;
  if (sVar6 == sVar4) {
    *outl = 0;
  }
  local_50 = (void *)((int)local_50 + sVar4);
  if (sVar6 == sVar4) {
    outl[1] = 0;
  }
joined_r0x000abb2a:
  if (((int)param_3 < 1) || ((int)outl[6] < 1)) goto LAB_000abc04;
  goto LAB_000abb34;
}

