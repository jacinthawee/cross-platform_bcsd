
int DES_set_key_checked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  if ((((((uint)(byte)odd_parity[(*key)[0]] == (uint)(*key)[0]) &&
        ((uint)(byte)odd_parity[(*key)[1]] == (uint)(*key)[1])) &&
       ((uint)(byte)odd_parity[(*key)[2]] == (uint)(*key)[2])) &&
      (((uint)(byte)odd_parity[(*key)[3]] == (uint)(*key)[3] &&
       ((uint)(byte)odd_parity[(*key)[4]] == (uint)(*key)[4])))) &&
     (((uint)(byte)odd_parity[(*key)[5]] == (uint)(*key)[5] &&
      (((uint)(byte)odd_parity[(*key)[6]] == (uint)(*key)[6] &&
       ((uint)(byte)odd_parity[(*key)[7]] == (uint)(*key)[7])))))) {
    iVar1 = (*(code *)PTR_memcmp_006a9ad0)(weak_keys,key,8);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65aef8,key,8);
      if (iVar1 != 0) {
        iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af00,key,8);
        if (iVar1 != 0) {
          iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af08,key,8);
          if (iVar1 != 0) {
            iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af10,key,8);
            if (iVar1 != 0) {
              iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af18,key,8);
              if (iVar1 != 0) {
                iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af20,key,8);
                if (iVar1 != 0) {
                  iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af28,key,8);
                  if (iVar1 != 0) {
                    iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af30,key,8);
                    if (iVar1 != 0) {
                      iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af38,key,8);
                      if (iVar1 != 0) {
                        iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af40,key,8);
                        if (iVar1 != 0) {
                          iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af48,key,8);
                          if (iVar1 != 0) {
                            iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af50,key,8);
                            if (iVar1 != 0) {
                              iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af58,key,8);
                              if (iVar1 != 0) {
                                iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af60,key,8);
                                if ((iVar1 != 0) &&
                                   (iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af68,key,8),
                                   iVar1 != 0)) {
                                  DES_set_key_unchecked(key,schedule);
                                  return 0;
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
            }
          }
        }
      }
    }
    return -2;
  }
  return -1;
}

