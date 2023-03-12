
int asn1_bio_write_part_1(int param_1,int param_2,uint *param_3)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  code *pcVar7;
  uint *puVar8;
  uint local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar8 = *(uint **)(param_1 + 0x20);
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = 0;
  if (puVar8 == (uint *)0x0) {
LAB_0062a960:
    if (local_2c == *(int *)puVar2) {
      return iVar3;
    }
    iVar3 = local_2c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (((param_2 != 0) && (-1 < (int)param_3)) && (*(int *)(iVar3 + 0x24) != 0)) {
      iVar3 = asn1_bio_write_part_1();
      return iVar3;
    }
    return 0;
  }
  uVar4 = *puVar8;
  iVar6 = 0;
  bVar1 = uVar4 < 5;
  puVar5 = param_3;
LAB_0062a87c:
  if (bVar1) {
    do {
      switch((uint)(&switchD_0062a890::switchdataD_0067c490)[uVar4] & 0xfffffffe) {
      case 0x62a898:
        iVar3 = (*(code *)PTR_ASN1_object_size_006a83e4)(0,puVar5,puVar8[7]);
        puVar8[4] = iVar3 - (int)puVar5;
        if ((int)puVar8[2] < iVar3 - (int)puVar5) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)("bio_asn1.c",0xe8,"ctx->buflen <= ctx->bufsize");
        }
        local_30 = puVar8[1];
        (*(code *)PTR_ASN1_put_object_006a83e8)(&local_30,0,puVar5,puVar8[7],puVar8[6]);
        puVar8[5] = (uint)puVar5;
        *puVar8 = 3;
      case 0x62a8fc:
        param_3 = (uint *)puVar8[4];
        iVar3 = (*(code *)PTR_BIO_write_006a6e14)
                          (*(undefined4 *)(param_1 + 0x24),puVar8[1] + puVar8[3]);
        if (iVar3 < 1) {
LAB_0062a9e8:
          param_2 = 0xf;
          (*(code *)PTR_BIO_clear_flags_006a8138)(param_1);
          (*(code *)PTR_BIO_copy_next_retry_006a8434)(param_1);
          if (iVar6 != 0) {
            iVar3 = iVar6;
          }
          goto LAB_0062a960;
        }
        uVar4 = puVar8[4];
        puVar8[4] = uVar4 - iVar3;
        if (uVar4 - iVar3 == 0) {
          puVar8[3] = 0;
          *puVar8 = 4;
switchD_0062a890_caseD_62aa70:
          param_3 = (uint *)puVar8[5];
          if ((int)puVar5 <= (int)(uint *)puVar8[5]) {
            param_3 = puVar5;
          }
          iVar3 = (*(code *)PTR_BIO_write_006a6e14)(*(undefined4 *)(param_1 + 0x24),param_2);
          if (0 < iVar3) {
            uVar4 = puVar8[5];
            iVar6 = iVar6 + iVar3;
            param_2 = param_2 + iVar3;
            puVar5 = (uint *)((int)puVar5 - iVar3);
            puVar8[5] = uVar4 - iVar3;
            if (uVar4 - iVar3 == 0) {
              *puVar8 = 2;
            }
            if (puVar5 == (uint *)0x0) {
              param_2 = 0xf;
              (*(code *)PTR_BIO_clear_flags_006a8138)(param_1);
              (*(code *)PTR_BIO_copy_next_retry_006a8434)(param_1);
              iVar3 = iVar6;
              goto LAB_0062a960;
            }
          }
          uVar4 = *puVar8;
          bVar1 = uVar4 < 5;
          goto LAB_0062a87c;
        }
        uVar4 = *puVar8;
        bVar1 = uVar4 < 5;
        puVar8[3] = puVar8[3] + iVar3;
        if (!bVar1) goto LAB_0062a94c;
        break;
      case 0x62a99c:
        param_3 = (uint *)puVar8[0xd];
        pcVar7 = (code *)puVar8[9];
        if ((int)param_3 < 1) goto LAB_0062a87c;
        uVar4 = puVar8[0xe];
        while( true ) {
          iVar3 = (*(code *)PTR_BIO_write_006a6e14)
                            (*(undefined4 *)(param_1 + 0x24),puVar8[0xc] + uVar4);
          if (iVar3 < 1) goto LAB_0062a9e8;
          param_3 = (uint *)(puVar8[0xd] - iVar3);
          puVar8[0xd] = (uint)param_3;
          if ((int)param_3 < 1) break;
          uVar4 = iVar3 + puVar8[0xe];
          puVar8[0xe] = uVar4;
        }
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)(param_1,puVar8 + 0xc,puVar8 + 0xd,puVar8 + 0xf);
        }
        puVar8[0xe] = 0;
        uVar4 = 2;
        bVar1 = true;
        *puVar8 = 2;
        break;
      case 0x62aa20:
        goto switchD_0062a890_caseD_62aa20;
      case 0x62aa70:
        goto switchD_0062a890_caseD_62aa70;
      }
    } while( true );
  }
LAB_0062a94c:
  param_2 = 0xf;
  (*(code *)PTR_BIO_clear_flags_006a8138)(param_1);
  iVar3 = 0;
  goto LAB_0062a960;
switchD_0062a890_caseD_62aa20:
  param_3 = puVar8 + 0xd;
  if (((code *)puVar8[8] != (code *)0x0) &&
     (iVar3 = (*(code *)puVar8[8])(param_1,puVar8 + 0xc,param_3,puVar8 + 0xf), iVar3 == 0)) {
    param_2 = 0xf;
    (*(code *)PTR_BIO_clear_flags_006a8138)(param_1);
    goto LAB_0062a960;
  }
  bVar1 = true;
  uVar4 = 2;
  if (0 < (int)puVar8[0xd]) {
    uVar4 = 1;
  }
  *puVar8 = uVar4;
  goto LAB_0062a87c;
}

