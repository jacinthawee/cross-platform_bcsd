
undefined4 dtls1_buffer_record_isra_6(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *ptr;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  iVar2 = (*(code *)PTR_pqueue_size_006a93b8)(*param_2);
  if (99 < iVar2) {
    return 0;
  }
  ptr = (undefined4 *)CRYPTO_malloc(0x3c,"d1_pkt.c",0xd8);
  iVar2 = (*(code *)PTR_pitem_new_006a93bc)(param_3,ptr);
  if (ptr == (undefined4 *)0x0) {
    if (iVar2 != 0) {
      (*(code *)PTR_pitem_free_006a939c)(iVar2);
    }
  }
  else {
    if (iVar2 != 0) {
      iVar5 = *(int *)(param_1 + 0x58);
      puVar3 = ptr + 6;
      uVar6 = *(undefined4 *)(param_1 + 0x50);
      *ptr = *(undefined4 *)(param_1 + 0x4c);
      ptr[1] = uVar6;
      uVar8 = *(undefined4 *)(iVar5 + 0xf0);
      uVar7 = *(undefined4 *)(iVar5 + 0xf4);
      uVar6 = *(undefined4 *)(iVar5 + 0xf8);
      ptr[2] = *(undefined4 *)(iVar5 + 0xec);
      ptr[3] = uVar8;
      ptr[4] = uVar7;
      ptr[5] = uVar6;
      iVar5 = *(int *)(param_1 + 0x58);
      puVar4 = (undefined4 *)(iVar5 + 0x10c);
      do {
        uVar9 = *puVar4;
        uVar8 = puVar4[1];
        uVar7 = puVar4[2];
        uVar6 = puVar4[3];
        puVar4 = puVar4 + 4;
        *puVar3 = uVar9;
        puVar3[1] = uVar8;
        puVar3[2] = uVar7;
        puVar3[3] = uVar6;
        puVar1 = PTR_pqueue_insert_006a93c0;
        puVar3 = puVar3 + 4;
      } while (puVar4 != (undefined4 *)(iVar5 + 300));
      *puVar3 = *puVar4;
      *(undefined4 **)(iVar2 + 8) = ptr;
      iVar5 = (*(code *)puVar1)(*param_2,iVar2);
      puVar1 = PTR_memset_006aab00;
      if (iVar5 != 0) {
        *(undefined4 *)(param_1 + 0x4c) = 0;
        *(undefined4 *)(param_1 + 0x50) = 0;
        (*(code *)puVar1)(*(int *)(param_1 + 0x58) + 0xec,0,0x10);
        (*(code *)PTR_memset_006aab00)(*(int *)(param_1 + 0x58) + 0x10c,0,0x24);
        iVar5 = ssl3_setup_buffers(param_1);
        if (iVar5 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf7,0x44,"d1_pkt.c",0x101);
          CRYPTO_free(ptr);
          (*(code *)PTR_pitem_free_006a939c)(iVar2);
          return 0;
        }
        return 1;
      }
      CRYPTO_free(ptr);
      (*(code *)PTR_pitem_free_006a939c)(iVar2);
      return 0;
    }
    CRYPTO_free(ptr);
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf7,0x44,"d1_pkt.c",0xdf);
  return 0;
}

