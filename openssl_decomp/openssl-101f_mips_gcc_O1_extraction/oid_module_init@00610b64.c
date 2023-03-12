
undefined4 oid_module_init(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  
  uVar4 = (*(code *)PTR_CONF_imodule_get_value_006aa8a8)();
  iVar5 = (*(code *)PTR_NCONF_get_section_006a7fd4)(param_2,uVar4);
  if (iVar5 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xae,0xac,"asn_moid.c",0x50);
    return 0;
  }
  iVar10 = 0;
  iVar6 = (*(code *)PTR_sk_num_006a7f2c)(iVar5);
  if (0 < iVar6) {
    do {
      iVar6 = (*(code *)PTR_sk_value_006a7f24)(iVar5,iVar10);
      pbVar12 = *(byte **)(iVar6 + 8);
      uVar4 = *(undefined4 *)(iVar6 + 4);
      pbVar7 = (byte *)(*(code *)PTR_strrchr_006aaab8)(pbVar12,0x2c);
      if (pbVar7 == (byte *)0x0) {
        iVar6 = (*(code *)PTR_OBJ_create_006a87a0)(pbVar12,uVar4,uVar4);
        if (iVar6 == 0) goto LAB_00610da4;
      }
      else {
        if (pbVar7[1] == 0) {
LAB_00610da4:
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xae,0xab,"asn_moid.c",0x58);
          return 0;
        }
        piVar8 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
        pbVar11 = pbVar7;
        do {
          pbVar11 = pbVar11 + 1;
        } while ((*(ushort *)(*piVar8 + (uint)*pbVar11 * 2) & 0x20) != 0);
        iVar6 = (*(code *)PTR_OBJ_create_006a87a0)(pbVar11,uVar4,0);
        if (iVar6 == 0) goto LAB_00610da4;
        do {
          pbVar11 = pbVar12;
          pbVar12 = pbVar11 + 1;
        } while ((*(ushort *)(*piVar8 + (uint)*pbVar11 * 2) & 0x20) != 0);
        bVar2 = pbVar7[-1];
        pbVar7 = pbVar7 + -1;
        while ((*(ushort *)(*piVar8 + (uint)bVar2 * 2) & 0x20) != 0) {
          bVar1 = pbVar11 == pbVar7;
          pbVar7 = pbVar7 + -1;
          if (bVar1) goto LAB_00610da4;
          bVar2 = *pbVar7;
        }
        pbVar7 = pbVar7 + (1 - (int)pbVar11);
        iVar9 = (*(code *)PTR_CRYPTO_malloc_006a8108)(pbVar7 + 1,"asn_moid.c",0x94);
        if (iVar9 == 0) goto LAB_00610da4;
        (*(code *)PTR_memcpy_006aabf4)(iVar9,pbVar11,pbVar7);
        puVar3 = PTR_OBJ_nid2obj_006a8240;
        pbVar7[iVar9] = 0;
        iVar6 = (*(code *)puVar3)(iVar6);
        *(int *)(iVar6 + 4) = iVar9;
      }
      iVar10 = iVar10 + 1;
      iVar6 = (*(code *)PTR_sk_num_006a7f2c)(iVar5);
    } while (iVar10 < iVar6);
  }
  return 1;
}

