
void frame_dummy(void)

{
  if (__JCR_END__ == 0) {
    register_tm_clones();
    return;
  }
  if (PTR__Jv_RegisterClasses_006aaaac != (undefined *)0x0) {
    (*(code *)PTR__Jv_RegisterClasses_006aaaac)();
  }
  register_tm_clones();
  return;
}

