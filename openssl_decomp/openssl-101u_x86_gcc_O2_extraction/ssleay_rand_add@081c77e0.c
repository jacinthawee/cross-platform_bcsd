
undefined4 ssleay_rand_add(undefined8 param_1)

{
  undefined4 uVar1;
  
  if (param_1._4_4_ != 0) {
    uVar1 = ssleay_rand_add_part_0();
    return uVar1;
  }
  return (undefined4)param_1;
}
