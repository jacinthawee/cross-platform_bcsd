
/* WARNING: Could not reconcile some variable overlaps */

int internal_verify(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  X509 *pXVar6;
  X509 *pXVar7;
  int iVar8;
  X509 *a;
  uint uVar9;
  uchar *puVar10;
  uchar uVar11;
  ASN1_TIME *extraout_v1;
  uchar *puVar12;
  int iVar13;
  uchar *puVar14;
  uchar *puVar15;
  undefined4 *in_t3;
  uchar *in_t4;
  uchar *puVar16;
  uchar *in_t5;
  uint in_t6;
  undefined *puVar17;
  EVP_PKEY *unaff_s3;
  X509 *pXVar18;
  code *pcVar19;
  char *unaff_s6;
  undefined4 *unaff_s7;
  code *pcVar20;
  int *unaff_s8;
  ASN1_TIME *local_7c;
  undefined4 *local_78;
  int local_70;
  undefined4 local_6c;
  int local_68;
  char *local_64;
  uint local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  uchar local_50 [12];
  char local_44;
  char local_43;
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar19 = *(code **)(param_1 + 0x20);
  pXVar6 = (X509 *)(*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(param_1 + 0x54));
  puVar4 = PTR_sk_value_006a6e24;
  puVar17 = (undefined *)((int)&pXVar6[-1].aux + 3);
  *(undefined **)(param_1 + 0x60) = puVar17;
  pXVar7 = (X509 *)(*(code *)puVar4)(*(undefined4 *)(param_1 + 0x54),puVar17);
  iVar8 = (**(code **)(param_1 + 0x28))(param_1,pXVar7,pXVar7);
  puVar4 = PTR_sk_value_006a6e24;
  a = pXVar7;
  if (iVar8 == 0) {
    if ((int)puVar17 < 1) {
      *(X509 **)(param_1 + 0x68) = pXVar7;
      *(undefined4 *)(param_1 + 100) = 0x15;
      iVar8 = (*pcVar19)(0,param_1);
      goto LAB_00578844;
    }
    puVar17 = (undefined *)((int)&pXVar6[-1].aux + 2);
    *(undefined **)(param_1 + 0x60) = puVar17;
    a = (X509 *)(*(code *)puVar4)(*(undefined4 *)(param_1 + 0x54),puVar17);
  }
  iVar8 = 1;
  pXVar6 = a;
  if ((int)puVar17 < 0) goto LAB_00578844;
  unaff_s6 = &local_44;
  unaff_s7 = &local_6c;
  unaff_s8 = &local_70;
  do {
    iVar8 = a->valid;
    *(undefined **)(param_1 + 0x60) = puVar17;
    if (iVar8 == 0) {
      if (a != pXVar7) {
        unaff_s3 = X509_get_pubkey(pXVar7);
joined_r0x005788a8:
        pXVar6 = a;
        if (unaff_s3 == (EVP_PKEY *)0x0) {
          *(X509 **)(param_1 + 0x68) = pXVar7;
          *(undefined4 *)(param_1 + 100) = 6;
          iVar8 = (*pcVar19)(0,param_1);
          if (iVar8 == 0) {
            iVar8 = 0;
            goto LAB_00578844;
          }
        }
        else {
          iVar8 = X509_verify(a,unaff_s3);
          if (iVar8 < 1) {
            *(X509 **)(param_1 + 0x68) = a;
            *(undefined4 *)(param_1 + 100) = 7;
            iVar8 = (*pcVar19)(0,param_1);
            if (iVar8 == 0) {
              (*(code *)PTR_EVP_PKEY_free_006a6e78)(unaff_s3);
              goto LAB_00578844;
            }
          }
        }
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(unaff_s3);
        goto LAB_00578568;
      }
      iVar8 = *(int *)(param_1 + 0x14);
      uVar9 = *(uint *)(iVar8 + 0xc);
      local_78 = in_t3;
      puVar16 = in_t4;
      if ((uVar9 & 0x4000) != 0) {
        unaff_s3 = X509_get_pubkey(pXVar7);
        goto joined_r0x005788a8;
      }
    }
    else {
LAB_00578568:
      iVar8 = *(int *)(param_1 + 0x14);
      uVar9 = *(uint *)(iVar8 + 0xc);
      local_78 = in_t3;
      puVar16 = in_t4;
    }
    a->valid = 1;
    pXVar18 = pXVar7;
    if ((uVar9 & 2) == 0) {
      unaff_s3 = (EVP_PKEY *)0x0;
      local_7c = a->cert_info->validity->notBefore;
      iVar8 = local_7c->type;
      iVar13 = local_7c->length;
      puVar10 = local_7c->data;
      if (iVar8 != 0x17) goto LAB_005785a4;
LAB_00578664:
      puVar15 = puVar10 + 10;
      if (iVar13 - 0xbU < 7) {
        uVar9 = (uint)puVar10 & 3;
        uVar2 = (uint)(puVar10 + 4) & 3;
        puVar14 = (uchar *)(iVar13 + -10);
        in_t6 = (uint)puVar10[9];
        puVar12 = (uchar *)((int)&local_54 + 2);
        uVar3 = (uint)(puVar10 + 3) & 3;
        local_5c = (*(int *)(puVar10 + -uVar9) << uVar9 * 8 |
                   (uint)in_t5 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar3 + 1) * 8 |
                   *(uint *)(puVar10 + 3 + -uVar3) >> (3 - uVar3) * 8;
        uVar9 = (uint)(puVar10 + 7) & 3;
        local_58 = (*(int *)(puVar10 + 4 + -uVar2) << uVar2 * 8 |
                   (uint)puVar16 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar9 + 1) * 8 |
                   *(uint *)(puVar10 + 7 + -uVar9) >> (3 - uVar9) * 8;
        uVar11 = *puVar15;
        local_54 = CONCAT13(puVar10[8],CONCAT12(puVar10[9],(short)local_54));
joined_r0x005785e8:
        if (((uVar11 == 'Z') || (local_78 = &local_5c, uVar11 == '-')) || (uVar11 == '+')) {
          in_t5 = &DAT_00000030;
          *puVar12 = '0';
          puVar12[1] = '0';
LAB_005786c4:
          puVar12[3] = '\0';
          puVar12[2] = 'Z';
          in_t4 = puVar12 + 2;
LAB_005786d0:
          local_78 = &local_5c;
          puVar16 = in_t4;
          if (uVar11 == 'Z') {
            if (puVar14 == (uchar *)0x1) goto LAB_00578790;
          }
          else if (((uVar11 == '+') || (uVar11 == '-')) &&
                  ((puVar14 == &DAT_00000005 &&
                   ((((int)(char)puVar15[1] - 0x30U & 0xff) < 10 &&
                    (puVar16 = (uchar *)(uint)((byte)(puVar15[2] - 0x30) < 10),
                    puVar16 != (uchar *)0x0)))))) {
            puVar16 = (uchar *)((char)puVar15[3] + -0x30);
            in_t5 = (uchar *)(uint)(((uint)puVar16 & 0xff) < 10);
            if (in_t5 != (uchar *)0x0) {
              in_t5 = (uchar *)((char)puVar15[4] + -0x30);
              in_t6 = ((int)(char)puVar15[1] - 0x30U) * 2;
              if (((uint)in_t5 & 0xff) < 10) {
                in_t4 = (uchar *)((int)puVar16 * 8);
LAB_00578790:
                local_60 = 0;
                local_6c = 0x18;
                local_68 = iVar8;
                local_64 = unaff_s6;
                if (unaff_s3 == (EVP_PKEY *)0x0) {
                  (*(code *)PTR_time_006a9adc)(unaff_s8);
                  if ((local_60 & 0x40) == 0) goto LAB_005787b0;
                  goto LAB_005787c8;
                }
                local_70 = unaff_s3->type;
                goto LAB_005787b0;
              }
            }
          }
        }
        else {
          in_t5 = puVar14 + -2;
          puVar16 = (uchar *)0x1;
          if (puVar14 != (uchar *)0x1) {
            bVar1 = puVar15[1];
            puVar16 = (uchar *)(uint)bVar1;
            *puVar12 = uVar11;
            puVar12[1] = bVar1;
            if (in_t5 != (uchar *)0x0) {
              uVar11 = puVar15[2];
              if (uVar11 != '.') {
                puVar15 = puVar15 + 2;
                puVar14 = in_t5;
                goto LAB_005786c4;
              }
              puVar16 = puVar14 + -3;
              if (puVar16 != (uchar *)0x0) {
                if ((byte)(puVar15[3] - 0x30) < 10) {
                  puVar16 = puVar14 + -4;
                  if (puVar16 == (uchar *)0x0) goto LAB_005789e4;
                  if ((byte)(puVar15[4] - 0x30) < 10) {
                    puVar16 = puVar14 + -5;
                    if (puVar16 == (uchar *)0x0) goto LAB_005789e4;
                    if ((byte)(puVar15[5] - 0x30) < 10) {
                      puVar12[3] = '\0';
                      puVar12[2] = 'Z';
                      if (puVar14 + -6 == (uchar *)0x0) goto LAB_005786f0;
                      uVar11 = puVar15[6];
                      puVar15 = puVar15 + 6;
                      puVar14 = puVar14 + -6;
                      in_t4 = puVar16;
                      goto LAB_005786d0;
                    }
                    puVar15 = puVar15 + 5;
                  }
                  else {
                    puVar15 = puVar15 + 4;
                  }
                }
                else {
                  puVar15 = puVar15 + 3;
                }
                in_t4 = &DAT_0000005a;
                uVar11 = *puVar15;
                puVar12[3] = '\0';
                puVar12[2] = 'Z';
                puVar14 = puVar16;
                goto LAB_005786d0;
              }
            }
LAB_005789e4:
            puVar12[3] = '\0';
            puVar12[2] = 'Z';
          }
        }
      }
    }
    else {
      unaff_s3 = (EVP_PKEY *)(iVar8 + 4);
      local_7c = a->cert_info->validity->notBefore;
      iVar8 = local_7c->type;
      iVar13 = local_7c->length;
      puVar10 = local_7c->data;
      if (iVar8 == 0x17) goto LAB_00578664;
LAB_005785a4:
      puVar15 = puVar10 + 0xc;
      if (iVar13 - 0xdU < 0xb) {
        uVar9 = (uint)puVar10 & 3;
        uVar2 = (uint)(puVar10 + 8) & 3;
        local_58 = *(uint *)(puVar10 + 4);
        puVar14 = (uchar *)(iVar13 + -0xc);
        puVar12 = local_50;
        uVar3 = (uint)(puVar10 + 3) & 3;
        in_t6 = (*(int *)(puVar10 + -uVar9) << uVar9 * 8 | in_t6 & 0xffffffffU >> (4 - uVar9) * 8) &
                -1 << (uVar3 + 1) * 8 | *(uint *)(puVar10 + 3 + -uVar3) >> (3 - uVar3) * 8;
        uVar9 = (uint)(puVar10 + 0xb) & 3;
        local_54 = (*(int *)(puVar10 + 8 + -uVar2) << uVar2 * 8 |
                   (uint)puVar16 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar9 + 1) * 8 |
                   *(uint *)(puVar10 + 0xb + -uVar9) >> (3 - uVar9) * 8;
        uVar11 = *puVar15;
        local_5c = in_t6;
        goto joined_r0x005785e8;
      }
    }
LAB_005786f0:
    *(X509 **)(param_1 + 0x68) = a;
    *(undefined4 *)(param_1 + 100) = 0xd;
    iVar8 = (**(code **)(param_1 + 0x20))(0,param_1);
    in_t3 = local_78;
    in_t4 = puVar16;
    pXVar7 = a;
    if (iVar8 == 0) goto LAB_00578840;
LAB_00578710:
    iVar8 = X509_cmp_time(pXVar7->cert_info->validity->notAfter,&unaff_s3->type);
    pXVar6 = pXVar7;
    if (iVar8 == 0) {
      *(X509 **)(param_1 + 0x68) = pXVar7;
      *(undefined4 *)(param_1 + 100) = 0xe;
      iVar8 = (**(code **)(param_1 + 0x20))(0,param_1);
      if (iVar8 == 0) {
        iVar8 = 0;
        pXVar7 = pXVar18;
        goto LAB_00578844;
      }
    }
    else if (iVar8 < 0) {
      *(X509 **)(param_1 + 0x68) = pXVar7;
      *(undefined4 *)(param_1 + 100) = 10;
      iVar8 = (**(code **)(param_1 + 0x20))(0,param_1);
      if (iVar8 == 0) {
        iVar8 = 0;
        pXVar7 = pXVar18;
        goto LAB_00578844;
      }
    }
    *(X509 **)(param_1 + 0x6c) = pXVar18;
    *(X509 **)(param_1 + 0x68) = pXVar7;
    iVar8 = (*pcVar19)(1,param_1);
    a = pXVar7;
    if (iVar8 == 0) goto LAB_00578840;
    puVar17 = puVar17 + -1;
    if (puVar17 == (undefined *)0xffffffff) {
      iVar8 = 1;
      pXVar7 = pXVar18;
LAB_00578844:
      do {
        if (local_2c == *(int *)puVar5) {
          return iVar8;
        }
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
        local_7c = extraout_v1;
        local_78 = in_t3;
        a = pXVar6;
LAB_005787b0:
        pcVar20 = (code *)PTR_ASN1_UTCTIME_adj_006a8ca8;
        if ((local_68 == 0x17) ||
           (pcVar20 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a8cac, local_68 == 0x18)) {
          iVar8 = (*pcVar20)(unaff_s7,local_70,0);
          pXVar18 = pXVar7;
        }
        else {
LAB_005787c8:
          iVar8 = (*(code *)PTR_ASN1_TIME_adj_006a8ef0)(unaff_s7,local_70,0);
          pXVar18 = pXVar7;
        }
        puVar16 = in_t4;
        if (iVar8 == 0) goto LAB_005786f0;
        pXVar7 = a;
        if (local_7c->type == 0x17) {
          iVar8 = (local_5c._0_1_ + -0x30) * 10 + local_5c._1_1_ + -0x30;
          iVar13 = (local_44 + -0x30) * 10 + local_43 + -0x30;
          if (iVar8 < 0x32) {
            iVar8 = iVar8 + 100;
          }
          if (iVar13 < 0x32) {
            iVar13 = iVar13 + 100;
          }
          in_t3 = local_78;
          if (iVar8 < iVar13) goto LAB_00578710;
          if (iVar8 <= iVar13) goto LAB_00578804;
        }
        else {
LAB_00578804:
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(local_78,unaff_s6);
          in_t3 = local_78;
          if ((iVar8 == 0) || (iVar8 < 1)) goto LAB_00578710;
        }
        *(X509 **)(param_1 + 0x68) = a;
        *(undefined4 *)(param_1 + 100) = 9;
        iVar8 = (**(code **)(param_1 + 0x20))(0,param_1);
        if (iVar8 != 0) goto LAB_00578710;
LAB_00578840:
        iVar8 = 0;
        pXVar6 = a;
        pXVar7 = pXVar18;
      } while( true );
    }
    a = (X509 *)(*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(param_1 + 0x54),puVar17);
  } while( true );
}

