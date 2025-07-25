#ifndef HEADERS_FUNCTIONS_ARM9_H_
#define HEADERS_FUNCTIONS_ARM9_H_

#include "arm9/itcm.h"
#include "arm9/libs.h"

void Svc_SoftReset(void);
void Svc_WaitByLoop(void);
void Svc_CpuSet(void);
void _start(void);
void MIi_UncompressBackward(void);
void do_autoload(void);
void StartAutoloadDoneCallback(void);
void OSi_ReferSymbol(void);
void NitroMain(void);
void InitMemAllocTable(void);
void SetMemAllocatorParams(get_alloc_arena_fn_t get_alloc_arena,
                           get_free_arena_fn_t get_free_arena);
struct mem_arena* GetAllocArenaDefault(struct mem_arena* arena, uint32_t flags);
struct mem_arena* GetFreeArenaDefault(struct mem_arena* arena, uint32_t flags);
void InitMemArena(struct mem_arena* arena, struct iovec* mem, struct mem_block* blocks,
                  uint32_t max_blocks);
uint32_t MemAllocFlagsToBlockType(uint32_t alloc_flags);
int FindAvailableMemBlock(struct mem_arena* arena, uint32_t alloc_flags, uint32_t len);
struct mem_block* SplitMemBlock(struct mem_arena* arena, uint32_t idx, uint32_t alloc_flags,
                                uint32_t len, uint32_t user_flags);
void* MemAlloc(uint32_t len, uint32_t flags);
void MemFree(void* ptr);
struct mem_arena* MemArenaAlloc(struct mem_arena* parent_arena, uint32_t len, uint32_t max_blocks,
                                uint32_t flags);
struct mem_arena* CreateMemArena(struct iovec* mem, uint32_t max_blocks);
void* MemLocateSet(struct mem_arena* arena, uint32_t len, uint32_t flags);
void MemLocateUnset(struct mem_arena* arena, void* ptr);
int RoundUpDiv256(int x);
bool UFixedPoint64CmpLt(int32_t x_upper, uint32_t x_lower, int32_t y_upper, uint32_t y_lower);
int MultiplyByFixedPoint(int x, fx32_8 mult_fp);
uint32_t UMultiplyByFixedPoint(uint32_t x, ufx32_8 mult_fp);
void IntToFixedPoint64(struct fx64_16* out, int x);
int FixedPoint64ToInt(struct fx64_16* x);
void FixedPoint32To64(struct fx64_16* out, fx32_8 x_fp);
void NegateFixedPoint64(struct fx64_16* x);
bool FixedPoint64IsZero(struct fx64_16* x);
bool FixedPoint64IsNegative(struct fx64_16* x);
bool FixedPoint64CmpLt(struct fx64_16* x, struct fx64_16* y);
void MultiplyFixedPoint64(struct fx64_16* prod, struct fx64_16* x, struct fx64_16* y);
void DivideFixedPoint64(struct fx64_16* quotient, struct fx64_16* dividend,
                        struct fx64_16* divisor);
void UMultiplyFixedPoint64(struct fx64_16* prod, struct fx64_16* x, struct fx64_16* y);
void UDivideFixedPoint64(struct fx64_16* quotient, struct fx64_16* dividend,
                         struct fx64_16* divisor);
void AddFixedPoint64(struct fx64_16* sum, struct fx64_16* x, struct fx64_16* y);
void ClampedLn(struct fx64_16* out, int x);
uint16_t GetRngSeed(void);
void SetRngSeed(uint16_t seed);
uint16_t Rand16Bit(void);
uint32_t RandInt(uint32_t n);
int RandRange(int x, int y);
uint32_t Rand32Bit(void);
uint32_t RandIntSafe(uint32_t n);
int RandRangeSafe(int x, int y);
void WaitForever(void);
uint16_t InterruptMasterDisable(void);
uint16_t InterruptMasterEnable(void);
void InitMemAllocTableVeneer(void);
void ZInit8(void* ptr);
bool PointsToZero(int* ptr);
void MemZero(void* ptr, uint32_t len);
void MemZero16(void* ptr, int len);
void MemZero32(void* ptr, int len);
void MemsetSimple(void* ptr, char val, uint32_t len);
void Memset32(void* ptr, int val, int len);
void MemcpySimple(void* dest, void* src, uint32_t n);
void Memcpy16(void* dest, void* src, int n);
void Memcpy32(void* dest, void* src, int n);
void TaskProcBoot(void);
bool EnableAllInterrupts(void);
float GetTime(void);
bool DisableAllInterrupts(void);
bool SoundResume(void);
void CardPullOutWithStatus(int status);
void CardPullOut(void);
void CardBackupError(void);
void HaltProcessDisp(int status);
bool OverlayIsLoaded(enum overlay_group_id group_id);
void LoadOverlay(enum overlay_group_id group_id);
void UnloadOverlay(enum overlay_group_id group_id);
void GetDsFirmwareUserSettingsVeneer(struct user_settings* settings);
void Rgb8ToRgb5(struct rgb5* target, struct rgba* source);
float EuclideanNorm(int* vec2);
void ClampComponentAbs(int* vec2, int max);
bool GetHeldButtons(int controller, undefined* btn_ptr);
bool GetPressedButtons(int controller, undefined* btn_ptr);
bool GetReleasedStylus(undefined* stylus_ptr);
void KeyWaitInit(void);
void DebugPrintSystemClock(void);
void GetSystemClock(struct system_clock* clock);
void SprintfSystemClock(struct system_clock* clock, char* str);
void DataTransferInit(void);
void DataTransferStop(void);
void FileInitVeneer(struct file_stream* file);
void FileOpen(struct file_stream* file, const char* filepath);
uint32_t FileGetSize(struct file_stream* file);
uint32_t FileRead(struct file_stream* file, void* buf, uint32_t size);
void FileSeek(struct file_stream* file, int offset, int whence);
void FileClose(struct file_stream* file);
void UnloadFile(void* ptr);
void LoadFileFromRom(struct iovec* iov, const char* filepath, uint32_t flags);
void TransformPaletteDataWithFlushDivideFade(struct palette_data* palette);
void UpdateFadeStatus(struct screen_fade* fstruct, int param_2, int duration);
bool HandleFades(struct screen_fade* fstruct);
int GetFadeStatus(struct screen_fade* fstruct);
void InitDebug(void);
void InitDebugFlag(void);
bool GetDebugFlag(enum debug_flag flag);
void SetDebugFlag(enum debug_flag flag, bool val);
void InitDebugStripped6(void);
int AppendProgPos(char* str, struct prog_pos_info* prog_pos, const char* msg);
void InitDebugStripped5(void);
void DebugPrintTrace(const char* msg, struct prog_pos_info* prog_pos);
void DebugDisplay(const char* fmt, ...);
void DebugPrint0(const char* fmt, ...);
void InitDebugLogFlag(void);
bool GetDebugLogFlag(enum debug_log_flag flag);
void SetDebugLogFlag(enum debug_log_flag flag, bool val);
void DebugPrint(uint8_t level, const char* fmt, ...);
void InitDebugStripped4(void);
void InitDebugStripped3(void);
void InitDebugStripped2(void);
void InitDebugStripped1(void);
void FatalError(struct prog_pos_info prog_pos, const char* fmt, ...);
void OpenAllPackFiles(void);
uint32_t GetFileLengthInPackWithPackNb(enum pack_file_id pack_id, uint32_t file_index);
uint32_t LoadFileInPackWithPackId(enum pack_file_id pack_id, uint32_t file_index,
                                  void* output_buffer);
void AllocAndLoadFileInPack(enum pack_file_id pack_id, uint32_t file_index,
                            struct pack_alloc_and_load_result* output, uint32_t malloc_flags);
void OpenPackFile(struct pack_file_opened* pack_file, const char* file_name);
uint32_t GetFileLengthInPack(struct pack_file_opened* pack_file, uint32_t file_index);
uint32_t LoadFileInPack(struct pack_file_opened* pack_file, void* output_buffer,
                        uint32_t file_index);
void GetDungeonResultMsg(union damage_source damage_source_or_result, char* buffer, int buffer_size,
                         undefined* param_4);
union damage_source GetDamageSource(enum move_id, enum item_id);
enum item_category GetItemCategoryVeneer(enum item_id item_id);
enum move_id GetItemMoveId16(enum item_id item_id);
bool IsThrownItem(enum item_id item_id);
bool IsNotMoney(enum item_id item_id);
bool IsEdible(enum item_id item_id);
bool IsHM(enum item_id item_id);
bool IsGummi(enum item_id item_id);
bool IsAuraBow(enum item_id item_id);
bool IsLosableItem(struct item* item);
bool IsTreasureBox(enum item_id item_id);
bool IsStorableItem(enum item_id item_id);
bool IsShoppableItem(enum item_id item_id);
bool IsValidTargetItem(enum item_id item_id);
bool IsItemUsableNow(struct item* item);
bool IsTicketItem(enum item_id item_id);
void InitItem(struct item* item, enum item_id item_id, uint16_t quantity, bool sticky);
void InitStandardItem(struct item* item, enum item_id item_id, bool sticky);
void InitBulkItem(struct bulk_item* item, enum item_id item_id);
void BulkItemToItem(struct item* item, struct bulk_item* bulk_item);
void ItemToBulkItem(struct bulk_item* bulk_item, struct item* item);
int GetDisplayedBuyPrice(struct item* item);
int GetDisplayedSellPrice(struct item* item);
int GetActualBuyPrice(struct item* item);
int GetActualSellPrice(struct item* item);
int FindItemInInventory(enum item_id item_id);
int SprintfStatic(char* str, const char* format, ...);
void ItemZInit(struct item* item);
bool AreItemsEquivalent(struct item* item1, struct item* item2, int bitmask);
int WriteItemsToSave(void* start_address, uint32_t total_length);
int ReadItemsFromSave(void* start_address, uint32_t total_length);
bool IsItemAvailableInDungeonGroup(enum dungeon_id dungeon_id, enum item_id item_id);
enum item_id GetItemIdFromList(int list_id, int category_num, int item_num);
enum item_id NormalizeTreasureBox(enum item_id item_id);
void SortItemList(struct item* item_list, int length);
void RemoveEmptyItems(struct item* list, int size);
void LoadItemPspi2n(void);
uint8_t GetExclusiveItemType(enum item_id item_id);
int GetExclusiveItemOffsetEnsureValid(enum item_id item_id);
bool IsItemValid(enum item_id item_id);
int16_t GetExclusiveItemParameter(enum item_id item_id);
enum item_category GetItemCategory(enum item_id item_id);
enum item_id EnsureValidItem(enum item_id item_id);
char* GetItemName(enum item_id item_id);
void GetItemNameFormatted(char* name_out, enum item_id item_id, bool flag1, bool flag2);
uint16_t GetItemBuyPrice(enum item_id item_id);
uint16_t GetItemSellPrice(enum item_id item_id);
uint8_t GetItemSpriteId(enum item_id item_id);
uint8_t GetItemPaletteId(enum item_id item_id);
uint8_t GetItemActionName(enum item_id item_id);
uint8_t GetThrownItemQuantityLimit(enum item_id, int limit_idx);
enum move_id GetItemMoveId(enum item_id item_id);
bool TestItemAiFlag(enum item_id item_id, enum item_flag flag);
bool IsItemInTimeDarkness(enum item_id item_id);
bool IsItemValidVeneer(enum item_id item_id);
void SetActiveInventoryToMain(void);
void AllInventoriesZInit(void);
void SpecialEpisodeInventoryZInit(void);
void RescueInventoryZInit(void);
void SetActiveInventory(enum team_id team_id);
int GetMoneyCarried(void);
void SetMoneyCarried(int amount);
void AddMoneyCarried(int amount);
int GetCurrentBagCapacity(void);
bool IsBagFull(void);
int GetNbItemsInBag(void);
int CountNbItemsOfTypeInBag(enum item_id item_id);
int CountItemTypeInBag(enum item_id item_id);
bool IsItemInBag(enum item_id item_id);
bool IsItemWithFlagsInBag(enum item_id item_id, int flags);
bool IsItemInTreasureBoxes(enum item_id item_id);
bool IsHeldItemInBag(struct item* item);
bool IsItemForSpecialSpawnInBag(void);
bool HasStorableItems(void);
int GetItemIndex(struct item* item);
int GetEquivItemIndex(struct item* item);
int GetEquippedThrowableItem(void);
int GetFirstUnequippedItemOfType(enum item_id item_id);
bool CopyItemAtIdx(int idx, struct item* item_out);
struct item* GetItemAtIdx(int idx);
void RemoveEmptyItemsInBag(void);
bool RemoveItemNoHole(int idx);
void RemoveItem(int idx);
void RemoveHeldItemNoHole(int held_idx);
bool RemoveItemByIdAndStackNoHole(struct item* item);
bool RemoveEquivItem(struct item* item);
bool RemoveEquivItemNoHole(struct item* item);
bool DecrementStackItem(struct item* item);
bool RemoveItemNoHoleCheck(int idx);
bool RemoveFirstUnequippedItemOfType(enum item_id item_id);
void RemoveAllItems(void);
void RemoveAllItemsStartingAt(int idx);
bool SpecialProcAddItemToBag(struct bulk_item* item);
bool AddItemToBagNoHeld(struct item* item);
bool AddItemToBag(struct item* item, int held_by);
void CleanStickyItemsInBag(void);
int CountStickyItemsInBag(void);
bool TransmuteHeldItemInBag(struct item* item);
void SetFlagsForHeldItemInBag(int held_by, int bitflags);
void RemoveHolderForItemInBag(struct item* item);
void SetHolderForItemInBag(int idx, struct item* item, int held_by);
void SortItemsInBag(void);
void RemovePokeItemsInBag(void);
bool IsStorageFull(void);
int CountNbOfItemsInStorage(void);
int CountNbOfValidItemsInStorage(void);
int CountNbOfValidItemsInTimeDarknessInStorage(void);
int CountNbItemsOfTypeInStorage(enum item_id item_id);
int CountItemTypeInStorage(struct bulk_item* bulk_item);
int GetEquivBulkItemIdxInStorage(struct bulk_item* bulk_item);
bool ConvertStorageItemAtIdxToBulkItem(int idx, struct bulk_item* bulk_item);
bool ConvertStorageItemAtIdxToItem(int idx, struct item* item);
bool RemoveItemAtIdxInStorage(int idx);
bool RemoveBulkItemInStorage(struct bulk_item* bulk_item);
bool RemoveItemInStorage(struct item* item);
void StorageZInit(void);
bool AddBulkItemToStorage(struct bulk_item* bulk_item);
bool AddItemToStorage(struct item* item);
void SortItemsInStorage(bool* param_1, int num_items_to_sort);
void AllKecleonShopsZInit(void);
void SpecialEpisodeKecleonShopZInit(void);
void SetActiveKecleonShop(enum team_id team_id);
int GetMoneyStored(void);
void SetMoneyStored(int amount);
void AddMoneyStored(int amount);
void RemoveItemFromKecleonShop1(int slot);
void SortKecleonItems1(void);
void GenerateKecleonItems1(enum kecleon_shop_version kecleon_shop_version);
bool AddItemToKecleonShop1(enum item_id item_id);
void RemoveItemFromKecleonShop2(int slot);
void SortKecleonItems2(void);
void GenerateKecleonItems2(enum kecleon_shop_version kecleon_shop_version);
bool AddItemToKecleonShop2(enum item_id item_id);
int GetExclusiveItemOffset(enum item_id item_id);
void ApplyExclusiveItemStatBoosts(enum item_id item_id, uint8_t* atk_boost, uint8_t* sp_atk_boost,
                                  uint8_t* def_boost, uint8_t* sp_def_boost);
void SetExclusiveItemEffect(uint32_t* effect_flags, enum exclusive_item_effect_id effect_id);
bool ExclusiveItemEffectFlagTest(uint32_t* effect_flags, enum exclusive_item_effect_id effect_id);
bool IsExclusiveItemIdForMonster(enum item_id item_id, enum monster_id monster_id,
                                 enum type_id type1, enum type_id type2);
bool IsExclusiveItemForMonster(struct item* item, enum monster_id monster_id, enum type_id type1,
                               enum type_id type2);
enum item_id BagHasExclusiveItemTypeForMonster(enum exclusive_item_effect_id effect_id,
                                               enum monster_id monster_id, enum type_id type1,
                                               enum type_id type2);
bool GetExclusiveItemForMonsterFromBag(struct item* item, enum exclusive_item_effect_id effect_id,
                                       enum monster_id monster_id, enum type_id type1,
                                       enum type_id type2);
int GetHpBoostFromExclusiveItems(undefined* param_1);
void ApplyGummiBoostsToGroundMonster(struct ground_monster* ground_monster, enum item_id item_id,
                                     bool not_boost_stats, struct gummi_result* gummi_result);
void ApplyGummiBoostsToTeamMember(struct team_member* team_member, enum item_id item_id,
                                  bool not_boost_stats, struct gummi_result* gummi_result);
int ApplySitrusBerryBoostToGroundMonster(struct ground_monster* ground_monster,
                                         int* attempted_hp_boost_out);
int ApplyLifeSeedBoostToGroundMonster(struct ground_monster* ground_monster,
                                      int* attempted_hp_boost_out);
int ApplyGinsengToGroundMonster(struct ground_monster* ground_monster,
                                struct move_id_16* move_id_out, int* attempted_move_boost_out);
int ApplyProteinBoostToGroundMonster(struct ground_monster* ground_monster,
                                     int* attempted_attack_boost_out);
int ApplyCalciumBoostToGroundMonster(struct ground_monster* ground_monster,
                                     int* attempted_sp_attack_boost_out);
int ApplyIronBoostToGroundMonster(struct ground_monster* ground_monster,
                                  int* attempted_defense_boost_out);
int ApplyZincBoostToGroundMonster(struct ground_monster* ground_monster,
                                  int* attempted_sp_defense_boost_out);
int ApplyNectarBoostToGroundMonster(struct ground_monster* ground_monster,
                                    int* attempted_iq_boost_out);
bool IsMonsterAffectedByGravelyrockGroundMode(struct ground_monster* ground_monster);
int ApplyGravelyrockBoostToGroundMonster(struct ground_monster* ground_monster,
                                         int* attempted_iq_boost_out);
void ApplyGummiBoostsGroundMode(struct monster_id_16* monster_id, uint16_t* monster_iq,
                                uint8_t* monster_offensive_stats, uint8_t* monster_defensive_stats,
                                enum item_id item_id, bool not_boost_stats,
                                struct gummi_result* gummi_result);
bool LoadSynthBin(void);
void CloseSynthBin(void);
undefined* GetSynthItem(int param_1);
void LoadWazaP(void);
void LoadWazaP2(void);
void UnloadCurrentWazaP(void);
char* GetMoveName(enum move_id move_id);
void FormatMoveString(char* string, struct move* move, undefined* type_print);
void FormatMoveStringMore(undefined* param_1, int param_2, struct move* move,
                          undefined* type_print);
void InitMove(struct move* move, enum move_id);
void InitMoveCheckId(struct move* move, enum move_id move_id);
void GetInfoMoveGround(struct ground_move* move, enum move_id move_id);
struct move_target_and_range GetMoveTargetAndRange(struct move* move, bool is_ai);
enum type_id GetMoveType(struct move* move);
uint8_t* GetMovesetLevelUpPtr(enum monster_id monster_id);
bool IsInvalidMoveset(int moveset_id);
undefined* GetMovesetHmTmPtr(enum monster_id monster_id);
undefined* GetMovesetEggPtr(enum monster_id monster_id);
uint8_t GetMoveAiWeight(struct move* move);
uint8_t GetMoveNbStrikes(struct move* move);
int GetMoveBasePower(struct move* move);
int16_t GetMoveBasePowerGround(struct ground_move* move);
uint8_t GetMoveAccuracyOrAiChance(struct move* move, int which);
uint8_t GetMoveBasePp(struct move* move);
int GetMaxPp(struct move* move);
uint8_t GetMoveMaxGinsengBoost(struct move* move);
uint8_t GetMoveMaxGinsengBoostGround(struct ground_move* move);
int GetMoveCritChance(struct move* move);
bool IsThawingMove(struct move* move);
bool IsAffectedByTaunt(struct move* move);
uint8_t GetMoveRangeId(struct move* move);
int GetMoveActualAccuracy(enum move_id move_id);
int GetMoveBasePowerFromId(enum move_id move_id);
bool IsMoveRangeString19(struct move* move);
char* GetMoveMessageFromId(enum move_id move_id);
int GetNbMoves(undefined* moveset);
int GetMovesetIdx(undefined* moveset, enum move_id move_id);
bool IsReflectedByMagicCoat(enum move_id move_id);
bool CanBeSnatched(enum move_id move_id);
bool FailsWhileMuzzled(enum move_id move_id);
bool IsSoundMove(struct move* move);
bool IsRecoilMove(enum move_id move_id);
void AllManip1(undefined4 param_1);
void AllManip2(undefined4 param_1);
void ManipMoves1v1(undefined* param_1, undefined* param_2);
void ManipMoves1v2(undefined* param_1, undefined* param_2);
void ManipMoves2v1(undefined* param_1, undefined* param_2);
void ManipMoves2v2(undefined* param_1, undefined* param_2);
void DungeonMoveToGroundMove(struct ground_move* dst, struct move* src);
void GroundToDungeonMoveset(undefined* dst, undefined* src);
void DungeonToGroundMoveset(undefined* dst, undefined* src);
void GetInfoGroundMoveset(undefined* moveset, struct move_id_16* moves);
int FindFirstFreeMovesetIdx(undefined* moveset);
void LearnMoves(undefined* moveset, struct move_id_16* moves);
void CopyMoveTo(undefined* write_info, void* buffer_write);
void CopyMoveFrom(undefined* read_info, void* buffer_read);
void CopyMovesetTo(undefined* write_info, void* buffer_write);
void CopyMovesetFrom(undefined* read_info, void* buffer_read);
bool Is2TurnsMove(enum move_id move_id);
bool IsRegularAttackOrProjectile(enum move_id move_id);
bool IsPunchMove(enum move_id move_id);
bool IsHealingWishOrLunarDance(enum move_id move_id);
bool IsCopyingMove(enum move_id move_id);
bool IsTrappingMove(enum move_id move_id);
bool IsOneHitKoMove(enum move_id move_id);
bool IsNot2TurnsMoveOrSketch(enum move_id move_id);
bool IsRealMove(enum move_id move_id);
bool IsMovesetValid(undefined* moveset);
bool IsRealMoveInTimeDarkness(enum move_id move_id);
bool IsMovesetValidInTimeDarkness(undefined* moveset);
int GetFirstNotRealMoveInTimeDarkness(undefined* moveset);
bool IsSameMove(undefined* moveset, struct move* move);
enum move_category GetMoveCategory(enum move_id move_id);
int GetPpIncrease(enum monster_id monster_id, uint32_t* iq_skill_flags);
void OpenWaza(int waza_id);
void SelectWaza(int waza_id);
void PlayBgmByIdVeneer(enum music_id music_id);
void PlayBgmByIdVolumeVeneer(enum music_id music_id, undefined param_2, int volume);
void PlaySeVolumeWrapper(int index);
void PlayBgmById(enum music_id music_id);
void PlayBgmByIdVolume(enum music_id music_id, undefined param_2, int volume);
void StopBgmCommand(void);
void PlaySeByIdVolume(int se_id, int volume);
void SendAudioCommand2(struct audio_command command);
struct audio_command* AllocAudioCommand(int status);
void SendAudioCommand(struct audio_command command);
void InitSoundSystem(void);
void ManipBgmPlayback(void);
void SoundDriverReset(void);
uint32_t LoadDseFile(struct iovec* iov, const char* filename);
undefined4 PlaySeLoad(int param_1);
bool IsSongOver(void);
void PlayBgm(int param_1, int param_2, int param_3);
void StopBgm(int param_1);
void ChangeBgm(int param_1, int param_2);
void PlayBgm2(int param_1, int param_2, int param_3);
void StopBgm2(int param_1);
void ChangeBgm2(int param_1, int param_2);
void PlayME(int param_1, int param_2, int param_3);
void StopME(int fade_out);
void PlaySe(int param_1, int param_2);
void PlaySeFullSpec(int param_1, int param_2, int param_3, int param_4);
void SeChangeVolume(int param_1, int param_2, int param_3);
void SeChangePan(int param_1, int param_2, int param_3);
void StopSe(int param_1, int param_2);
void ExecuteCopyToFlatVramCommand(struct copy_to_obj_vram_order* order);
uint32_t DecodeFragmentByteAssemblyTable(struct wan_fragment_bytes_assembly_entry* entry,
                                         void* dst);
void CopyAndInterleaveWrapper(uint16_t* dst, uint16_t* src, uint32_t len, uint8_t val);
void InitAnimationControl(struct animation_control* animation_control);
void InitAnimationControlWithSet(struct animation_control* animation_control);
void SetSpriteIdForAnimationControl(struct animation_control* anim_ctrl, uint16_t sprite_id);
void SetAnimationForAnimationControlInternal(struct animation_control* anim_ctrl,
                                             struct wan_header* wan_header, int animation_group_id,
                                             int animation_id, int unk1, int low_palette_pos,
                                             int unk2, int unk3, int palette_bank);
void SetAnimationForAnimationControl(struct animation_control* anim_ctrl, int animation_key,
                                     enum direction_id direction, int unk1, int low_palette_pos,
                                     int unk2, int unk3, int unk4);
struct wan_header* GetWanForAnimationControl(struct animation_control* anim_ctrl);
void SetAndPlayAnimationForAnimationControl(struct animation_control* anim_ctrl, int animation_key,
                                            enum direction_id direction, int unk1,
                                            int low_palette_pos, int unk2, int unk3, int unk4);
void SwitchAnimationControlToNextFrame(struct animation_control* anim_ctrl);
void LoadAnimationFrameAndIncrementInAnimationControl(struct animation_control* anim_ctrl,
                                                      struct wan_animation_frame* anim_frame);
uint32_t AnimationControlGetAllocForMaxFrame(struct animation_control* anim_ctrl);
void DeleteWanTableEntry(struct wan_table* wan_table, int wan_id);
int AllocateWanTableEntry(struct wan_table* wan_table);
int FindWanTableEntry(struct wan_table* wan_table, const char* path);
int GetLoadedWanTableEntry(struct wan_table* wan_table, enum pack_file_id pack_id,
                           uint16_t file_index);
void InitWanTable(struct wan_table* wan_table);
int LoadWanTableEntry(struct wan_table* wan_table, const char* path, uint32_t flags);
int LoadWanTableEntryFromPack(struct wan_table* wan_table, enum pack_file_id pack_id,
                              uint16_t file_index, uint32_t alloc_flags, bool is_compressed);
int LoadWanTableEntryFromPackUseProvidedMemory(struct wan_table* wan_table,
                                               enum pack_file_id pack_id, uint16_t file_index,
                                               void* sprite_storage, bool is_compressed);
int ReplaceWanFromBinFile(struct wan_table* wan_table, int wan_id, enum pack_file_id pack_id,
                          uint16_t file_index, bool compressed);
void DeleteWanTableEntryVeneer(struct wan_table* wan_table, int wan_id);
bool WanHasAnimationGroup(struct wan_header* wan_header, uint16_t animation_group_id);
bool WanTableSpriteHasAnimationGroup(uint16_t sprite_id, uint16_t animation_group_id);
enum wan_sprite_type SpriteTypeInWanTable(uint16_t sprite_id);
void LoadWteFromRom(struct wte_handle* handle, const char* path, uint32_t flags);
void LoadWteFromFileDirectory(struct wte_handle* handle, enum pack_file_id pack_id,
                              uint16_t file_index, uint32_t malloc_flags);
void UnloadWte(struct wte_handle* handle);
undefined* LoadWtuFromBin(int bin_file_id, int file_id, int load_type);
void ProcessWte(undefined* wte_header_ptr, undefined4 pal_vram_offset,
                undefined4 pal_texture_vram_offset_upper, undefined4 pal_texture_vram_offset_lower);
void DelayWteFree(struct wte_handle* handle);
void ResetPlannedVramTransfer(struct delayed_texture_vram_container* container);
uint32_t PlanCopyTextureToTextureVram(struct delayed_texture_vram_container* container,
                                      void* image_pointer, uint32_t dest_vram_offset,
                                      uint32_t image_length,
                                      enum delayed_texture_vram_order_type order_type);
void PerformPlannedTextureVramTransfer(struct delayed_texture_vram_container* container);
void GeomSetTexImageParam(int texture_format, int texture_coordinates_transformation_modes,
                          int texture_s_size, int texture_t_size, int repeat_s_t, int flip_s_t,
                          bool color_0, int vram_offset);
void GeomSetVertexCoord16(int x, int y, int z);
void InitRender3dData(void);
void GeomSwapBuffers(void);
void InitRender3dElement64(struct render_3d_element_64* element64);
void Render3d64Texture0x7(struct render_3d_element_64* element64);
void Render3d64WindowFrame(struct render_3d_element_64* element64);
void EnqueueRender3d64Tiling(struct render_3d_element_64* element64);
void Render3d64Tiling(struct render_3d_element_64* element64);
void Render3d64Quadrilateral(struct render_3d_element_64* element64);
void Render3d64RectangleMulticolor(struct render_3d_element_64* element64);
void Render3d64Rectangle(struct render_3d_element_64* element64);
void Render3d64Nothing(struct render_3d_element_64* element64);
void Render3d64Texture(struct render_3d_element_64* element64);
void Render3dElement64(struct render_3d_element_64* element64);
int HandleSir0Translation(uint8_t** dst, uint8_t* src);
void ConvertPointersSir0(undefined* sir0_ptr);
int HandleSir0TranslationVeneer(uint8_t** dst, uint8_t* src);
int DecompressAtNormalVeneer(undefined* addr_decomp, int expected_size, undefined* at_ptr);
int DecompressAtNormal(undefined* addr_decomp, int expected_size, undefined* at_ptr);
int DecompressAtHalf(undefined* addr_decomp, int expected_size, undefined* at_ptr, int high_nibble);
int DecompressAtFromMemoryPointerVeneer(undefined* addr_decomp, int expected_size,
                                        undefined* at_ptr);
int DecompressAtFromMemoryPointer(undefined* addr_decomp, int expected_size, undefined* at_ptr);
void WriteByteFromMemoryPointer(uint8_t byte);
int GetAtSize(undefined* at_ptr, int param_2);
int GetLanguageType(void);
int GetLanguage(void);
bool StrcmpTag(const char* s1, const char* s2);
int AtoiTag(const char* s);
int AnalyzeText(undefined* buf);
int PreprocessString(char* output, int output_size, const char* format,
                     struct preprocessor_flags flags, struct preprocessor_args* args);
int PreprocessStringFromId(char* output, int output_size, int string_id,
                           struct preprocessor_flags flags, struct preprocessor_args* args);
bool StrcmpTagVeneer(const char* s1, const char* s2);
int AtoiTagVeneer(const char* s);
void InitPreprocessorArgs(struct preprocessor_args* args);
char* SetStringAccuracy(char* s, int param_2);
char* SetStringPower(char* s, int param_2);
char* GetRankString(char* s, int rank_and_flags);
char* GetCurrentTeamNameString(char* buffer, int param_2);
char* GetBagNameString(char* buffer);
char* GetDungeonResultString(int string_number);
void SetQuestionMarks(char* s);
void StrcpySimple(char* dest, const char* src);
void StrncpySimple(char* dest, const char* src, uint32_t n);
void StrncpySimpleNoPad(char* dest, const char* src, uint32_t n);
int StrncmpSimple(const char* s1, const char* s2, uint32_t n);
void StrncpySimpleNoPadSafe(char* dest, const char* src, uint32_t n);
void StrcpyName(char* dest, const char* src);
void StrncpyName(char* dest, const char* src, uint32_t n);
void GetStringFromFile(char* buf, int string_id);
void LoadStringFile(void);
uint8_t* AllocateTemp1024ByteBufferFromPool(void);
void GetStringFromFileVeneer(char* buf, int string_id);
char* StringFromId(int string_id);
void CopyStringFromId(char* buf, int string_id);
void CopyNStringFromId(char* buf, int string_id, int buf_len);
void LoadTblTalk(void);
int GetTalkLine(int personality_idx, int group_id, int restrictions);
bool IsAOrBPressed(void);
void DrawTextInWindow(int window_id, int x, int y, char* string);
uint8_t GetCharWidth(char symbol);
int GetColorCodePaletteOffset(char symbol);
uint8_t DrawChar(int window_id, int x, int y, char symbol, int color_offset);
struct window* GetWindow(int window_id);
int NewWindowScreenCheck(struct window_params* params, uint8_t param_2);
int NewWindow(struct window_params* params, uint8_t param_2);
void SetScreenWindowsColor(int palette_idx, bool upper_screen);
void SetBothScreensWindowsColor(int palette_idx);
void UpdateWindow(int window_id);
void ClearWindow(int window_id);
void DeleteWindow(int window_id);
void GetWindowRectangle(int window_id, struct window_rectangle* rect_out);
void* GetWindowContents(int window_id);
void LoadCursors(void);
void InitWindowTrailer(struct window_trailer* trailer);
void LoadAlert(void);
void PrintClearMark(int mark_id, int x, int y, undefined param_4);
void PrintBadgeMark(enum rank badge_id, int x, int y, undefined param_4);
void PrintMark(int file, int id_in_file, int x, int y, undefined param_5);
int CreateParentMenuFromStringIds(struct window_params* params, struct window_flags flags,
                                  struct window_extra_info* window_extra_info,
                                  struct simple_menu_id_item* menu_items);
bool IsEmptyString(const char* s);
int CreateParentMenu(struct window_params* params, struct window_flags flags,
                     struct window_extra_info* window_extra_info,
                     struct simple_menu_ptr_item* menu_items);
int CreateParentMenuWrapper(struct window_params* params, struct window_flags flags,
                            struct window_extra_info* window_extra_info,
                            struct simple_menu_ptr_item* menu_items);
int CreateParentMenuInternal(struct window_params* params, struct window_flags flags,
                             struct window_extra_info* window_extra_info,
                             struct simple_menu_item* menu_items);
void ResumeParentMenu(int window_id);
void SetParentMenuState7(int window_id);
void CloseParentMenu(int window_id);
bool IsParentMenuActive(int window_id);
bool CheckParentMenuField0x1A0(int window_id);
void UpdateParentMenu(struct window* window);
int CreateSimpleMenuFromStringIds(struct window_params* params, struct window_flags flags,
                                  struct window_extra_info* window_extra_info,
                                  struct simple_menu_id_item* menu_items, int n_items);
int CreateSimpleMenu(struct window_params* params, struct window_flags flags,
                     struct window_extra_info* window_extra_info,
                     struct simple_menu_item* menu_items, int n_items);
int CreateSimpleMenuInternal(struct window_params* params, struct window_flags flags,
                             struct window_extra_info* window_extra_info,
                             struct simple_menu_item* menu_items, int n_items);
void ResumeSimpleMenu(int window_id);
void CloseSimpleMenu(int window_id);
bool IsSimpleMenuActive(int window_id);
bool CheckSimpleMenuField0x1A0(int window_id);
int GetSimpleMenuField0x1A4(int window_id);
int GetSimpleMenuResult(int window_id);
void UpdateSimpleMenu(struct window* window);
void SetSimpleMenuField0x1AC(int window_id, int value);
int CreateAdvancedMenu(struct window_params* params, struct window_flags flags,
                       struct window_extra_info* window_extra_info,
                       advanced_menu_entry_fn_t entry_fn, int n_options, int n_opt_per_page);
void ResumeAdvancedMenu(int window_id);
void CloseAdvancedMenu(int window_id);
bool IsAdvancedMenuActive2(int window_id);
bool IsAdvancedMenuActive(int window_id);
int GetAdvancedMenuCurrentOption(int window_id);
int GetAdvancedMenuResult(int window_id);
void UpdateAdvancedMenu(struct window* window);
int CreateCollectionMenu(struct window_params* params, struct window_flags flags,
                         struct window_extra_info* window_extra_info,
                         unk_collection_menu_fn_t param_4, undefined4 param_5, int n_options,
                         int n_opt_per_page);
void SetCollectionMenuField0x1BC(int window_id, int value);
void SetCollectionMenuWidth(int window_id, int width);
void CloseCollectionMenu(int window_id);
bool IsCollectionMenuActive(int window_id);
void SetCollectionMenuField0x1C8(int window_id, uint8_t value);
void SetCollectionMenuField0x1A0(int window_id, undefined4 value);
void SetCollectionMenuField0x1A4(int window_id, undefined4 value);
void SetCollectionMenuVoidFn(int window_id, unk_collection_menu_void_fn_t fn);
void UpdateCollectionMenu(struct window* window);
void SetCollectionMenuField0x1B2(int window_id, undefined4 value);
bool IsCollectionMenuState3(int window_id);
int CreateOptionsMenu(struct window_params* params, struct window_flags flags,
                      struct window_extra_info* window_extra_info,
                      struct options_menu_id_item* menu_items, int n_items, int* option_states);
void CloseOptionsMenu(int window_id);
bool IsOptionsMenuActive(int window_id);
bool CheckOptionsMenuField0x1A4(int window_id);
void GetOptionsMenuStates(int window_id, int* option_states);
bool GetOptionsMenuResult(int window_id);
void UpdateOptionsMenu(struct window* window);
int CreateDebugMenu(struct window_params* params, struct window_flags flags,
                    struct window_extra_info* window_extra_info, uint16_t* menu_item_string_ids,
                    int n_items, undefined* param_6);
void CloseDebugMenu(int window_id);
bool IsDebugMenuActive(int window_id);
bool CheckDebugMenuField0x1A4(int window_id);
void UpdateDebugMenu(struct window* window);
int CreateScrollBoxSingle(struct window_params* params, struct window_flags flags,
                          struct window_extra_info* window_extra_info, uint16_t string_id1,
                          struct preprocessor_args* args1, uint16_t string_id2,
                          struct preprocessor_args* args2);
int CreateScrollBoxMulti(struct window_params* params, struct window_flags flags,
                         struct window_extra_info* window_extra_info, int n_strings,
                         uint16_t* string_ids1, struct preprocessor_args* args1,
                         uint16_t* string_ids2, struct preprocessor_args* args2);
void SetScrollBoxState7(int window_id);
void CloseScrollBox(int window_id);
bool IsScrollBoxActive(int window_id);
void UpdateScrollBox(struct window* window);
int CreateDialogueBox(struct window_params* params);
void CloseDialogueBox(int window_id);
bool IsDialogueBoxActive(int window_id);
void ShowStringIdInDialogueBox(int window_id, struct preprocessor_flags flags, int string_id,
                               struct preprocessor_args* args);
void ShowStringInDialogueBox(int window_id, struct preprocessor_flags flags, char* string,
                             struct preprocessor_args* args);
void ShowDialogueBox(int window_id);
void ReadStringFromDialogueBox(int window_id, char* buffer, uint32_t n);
void UpdateDialogueBox(struct window* window);
int CreatePortraitBox(enum screen screen, uint32_t palette_idx, bool framed);
void ClosePortraitBox(int window_id);
bool PortraitBoxNeedsUpdate(int window_id);
void ShowPortraitInPortraitBox(int window_id, struct portrait_params* portrait);
void HidePortraitBox(int window_id);
void UpdatePortraitBox(struct window* window);
int CreateTextBox(struct window_params* params, text_box_callback_fn_t cb);
int CreateTextBoxWithArg(struct window_params* params, text_box_callback_with_arg_fn_t cb,
                         void* cb_arg);
void CloseTextBox(int window_id);
void CloseTextBox2(int window_id);
struct text_box* CreateTextBoxInternal(struct window_params* params);
void UpdateTextBox(struct window* window);
bool IsTextBoxActive(int window_id);
int CreateAreaNameBox(struct window_params* params, struct window_flags flags,
                      struct window_extra_info* window_extra_info, uint32_t id);
void SetAreaNameBoxState3(int window_id);
void CloseAreaNameBox(int window_id);
bool IsAreaNameBoxActive(int window_id);
void UpdateAreaNameBox(struct window* window);
int CreateControlsChart(struct window_params* params, struct window_flags flags,
                        struct window_extra_info* window_extra_info, uint16_t string_id);
void CloseControlsChart(int window_id);
bool IsControlsChartActive(int window_id);
void UpdateControlsChart(struct window* window);
int CreateAlertBox(struct window_params* params);
void CloseAlertBox(int window_id);
bool IsAlertBoxActive(int window_id);
void UpdateAlertBox(struct window* window);
int CreateAdvancedTextBox(struct window_params* params, struct window_flags flags,
                          struct window_extra_info* extra_info, text_box_callback_fn_t cb,
                          int n_items);
int CreateAdvancedTextBoxWithArg(struct window_params* params, struct window_flags flags,
                                 struct window_extra_info* extra_info,
                                 text_box_callback_with_arg_fn_t cb, void* cb_arg, int n_items);
struct advanced_text_box* CreateAdvancedTextBoxInternal(struct window_params* params,
                                                        struct window_flags flags,
                                                        struct window_extra_info* extra_info,
                                                        int n_items, int n_items_per_page);
void SetAdvancedTextBoxPartialMenu(int window_id, bool partial_menu);
void SetAdvancedTextBoxField0x1C4(int window_id, uint8_t value);
void SetAdvancedTextBoxField0x1C2(int window_id);
void CloseAdvancedTextBox2(int window_id);
void SetAdvancedTextBoxState5(int window_id);
void CloseAdvancedTextBox(int window_id);
bool IsAdvancedTextBoxActive(int window_id);
uint32_t GetAdvancedTextBoxFlags2(int window_id);
void SetUnkAdvancedTextBoxFn(int window_id, unk_advanced_text_box_fn_t fn);
void SetUnkAdvancedTextBoxWindowFn(int window_id, unk_advanced_text_box_window_fn_t fn);
void UpdateAdvancedTextBox(struct window* window);
void PlayAdvancedTextBoxInputSound(int window_id, int index);
int CreateTeamSelectionMenu(struct window_params* params, struct window_flags flags,
                            struct window_extra_info* window_extra_info,
                            team_selection_menu_get_item_fn_t get_item, int n_items,
                            int n_items_per_page);
void CloseTeamSelectionMenu(int window_id);
bool IsTeamSelectionMenuActive(int window_id);
void UpdateTeamSelectionMenu(struct window* window);
bool IsTeamSelectionMenuState3(int window_id);
int CalcMenuHeightDiv8(struct window_flags flags, struct window_extra_info* extra_info,
                       int* n_options, int* n_opt_per_page);
void InitWindowInput(struct window_input_ctx* input_ctx, struct window_flags flags,
                     struct window_extra_info* window_extra_info, struct window_rectangle* rect,
                     int n_items, int n_items_per_page);
bool IsMenuOptionActive(undefined* param_1);
void PlayWindowInputSound(struct window_input_ctx* input_ctx, int index);
void InitInventoryMenuInput(struct inventory_menu_input_ctx* input_ctx, struct window_flags flags,
                            struct window_extra_info* window_extra_info,
                            struct window_rectangle* rect, int n_items, int n_items_per_page,
                            undefined param_7);
int SetupAndShowKeyboard(int menu_type, char* buffer1, char* buffer2);
int ShowKeyboard(int menu_type, char* buffer1, int param_3, char* buffer2);
int GetKeyboardStatus(void);
int GetKeyboardStringResult(void);
char* TeamSelectionMenuGetItem(char* buffer, int member_idx);
void PrintMoveOptionMenu(void);
void PrintIqSkillsMenu(enum monster_id monster_id, uint32_t* iq_skills_flags, int monster_iq,
                       bool is_blinded);
bool GetNotifyNote(void);
void SetNotifyNote(bool flag);
void InitSpecialEpisodeHero(void);
void EventFlagBackupVeneer(void);
void InitMainTeamAfterQuiz(void);
void InitSpecialEpisodePartners(void);
void InitSpecialEpisodeExtraPartner(void);
void ReadStringSave(char* buf);
bool CheckStringSave(const char* buf);
int WriteSaveFile(undefined* save_info, undefined* buf, int size);
int ReadSaveFile(undefined* save_info, undefined* buf, int size);
void CalcChecksum(undefined* save_info, int size);
bool CheckChecksumInvalid(undefined* save_info, int size);
int NoteSaveBase(int param_1);
void WriteQuickSaveInfo(undefined* buf, int size);
undefined4 ReadSaveHeader(undefined4* param_1, undefined4 param_2, undefined4 param_3,
                          undefined4 param_4);
int NoteLoadBase(void);
int ReadQuickSaveInfo(undefined* buf, int size);
enum game_mode GetGameMode(void);
void InitScriptVariableValues(void);
void InitEventFlagScriptVars(void);
void ZinitScriptVariable(void* local_var_vals, enum script_var_id id);
void LoadScriptVariableRaw(struct script_var_desc* var, void* local_var_vals,
                           enum script_var_id id);
int LoadScriptVariableValue(void* local_var_vals, enum script_var_id id);
int LoadScriptVariableValueAtIndex(void* local_var_vals, enum script_var_id id, int idx);
void SaveScriptVariableValue(void* local_var_vals, enum script_var_id id, int val);
void SaveScriptVariableValueAtIndex(void* local_var_vals, enum script_var_id id, int idx, int val);
int LoadScriptVariableValueSum(void* local_var_vals, enum script_var_id id);
void LoadScriptVariableValueBytes(enum script_var_id id, void* dest, uint32_t n);
void SaveScriptVariableValueBytes(enum script_var_id id, void* src, uint32_t n);
bool ScriptVariablesEqual(void* local_var_vals, enum script_var_id id1, enum script_var_id id2);
void EventFlagResume(void);
void EventFlagBackup(void);
int DumpScriptVariableValues(void* dest);
bool RestoreScriptVariableValues(void* src);
void InitScenarioScriptVars(void);
void SetScenarioScriptVar(enum script_var_id id, uint8_t val0, uint8_t val1);
int GetSpecialEpisodeType(void);
void SetSpecialEpisodeType(enum special_episode_type special_episode_type);
int GetExecuteSpecialEpisodeType(void);
bool IsSpecialEpisodeOpen(enum special_episode_type special_episode_type);
bool HasPlayedOldGame(void);
bool GetPerformanceFlagWithChecks(int flag_id);
int GetScenarioBalance(void);
void ScenarioFlagBackup(void);
void InitWorldMapScriptVars(void);
void InitDungeonListScriptVars(void);
void SetDungeonConquest(enum dungeon_id dungeon_id, int bit_value);
enum dungeon_mode GetDungeonMode(enum dungeon_id dungeon_id);
struct global_progress* GlobalProgressAlloc(void);
void ResetGlobalProgress(void);
void SetMonsterFlag1(enum monster_id monster_id);
bool GetMonsterFlag1(enum monster_id monster_id);
void SetMonsterFlag2(enum monster_id monster_id);
bool HasMonsterBeenAttackedInDungeons(enum monster_id monster_id);
void SetDungeonTipShown(int tip_id);
bool GetDungeonTipShown(int tip_id);
void SetMaxReachedFloor(enum dungeon_id dungeon_id, int max_floor);
int GetMaxReachedFloor(enum dungeon_id dungeon_id);
void IncrementNbAdventures(void);
int GetNbAdventures(void);
bool CanMonsterSpawn(enum monster_id monster_id);
void IncrementExclusiveMonsterCounts(enum monster_id monster_id);
void CopyProgressInfoTo(undefined* write_info, undefined4 param_2, undefined4 param_3, int param_4);
undefined4 CopyProgressInfoFromScratchTo(void* start_addr, uint32_t total_len);
void CopyProgressInfoFrom(undefined* read_info);
undefined4 CopyProgressInfoFromScratchFrom(void* start_addr, uint32_t total_len);
void InitKaomadoStream(void);
void InitPortraitParams(struct portrait_params* portrait);
void InitPortraitParamsWithMonsterId(struct portrait_params* portrait, enum monster_id monster_id);
void SetPortraitEmotion(struct portrait_params* portrait, enum portrait_emotion emotion);
void SetPortraitLayout(struct portrait_params* portrait, uint8_t layout_idx);
void SetPortraitOffset(struct portrait_params* portrait, struct vec2* offset);
void AllowPortraitDefault(struct portrait_params* portrait, bool allow);
bool IsValidPortrait(struct portrait_params* portrait);
bool LoadPortrait(struct portrait_params* portrait, struct kaomado_buffer* buf);
bool WonderMailPasswordToMission(char* password, struct mission* mission_data);
void MissionToWonderMailPassword(char* password, struct mission* mission_data);
void SetEnterDungeon(enum dungeon_id dungeon_id);
void InitDungeonInit(struct dungeon_init* dungeon_init_data, enum dungeon_id dungeon_id);
bool IsNoLossPenaltyDungeon(enum dungeon_id dungeon_id);
undefined CheckMissionRestrictions(undefined param_1);
int GetNbFloors(enum dungeon_id dungeon_id);
int GetNbFloorsPlusOne(enum dungeon_id dungeon_id);
enum dungeon_group_id GetDungeonGroup(enum dungeon_id dungeon_id);
int GetNbPrecedingFloors(enum dungeon_id dungeon_id);
int GetNbFloorsDungeonGroup(enum dungeon_id dungeon_id);
void DungeonFloorToGroupFloor(struct dungeon_group_and_group_floor* out_group_data,
                              struct dungeon_floor_pair* dungeon_and_floor);
enum mission_rank GetMissionRank(struct dungeon_floor_pair* dungeon_and_floor);
int GetOutlawLevel(struct dungeon_floor_pair* dungeon_and_floor);
int GetOutlawLeaderLevel(struct dungeon_floor_pair* dungeon_and_floor);
int GetOutlawMinionLevel(struct dungeon_floor_pair* dungeon_and_floor);
void AddGuestMonster(struct dungeon_init* dungeon_init_data, int guest_number,
                     struct guest_monster* guest_monster);
int GetGroundNameId(int param_1);
void SetAdventureLogStructLocation(void);
void SetAdventureLogDungeonFloor(struct dungeon_floor_pair dungeon_floor);
struct dungeon_floor_pair GetAdventureLogDungeonFloor(void);
void ClearAdventureLogStruct(void);
void SetAdventureLogCompleted(uint32_t entry_id);
bool IsAdventureLogNotEmpty(void);
bool GetAdventureLogCompleted(uint32_t entry_id);
void IncrementNbDungeonsCleared(void);
uint32_t GetNbDungeonsCleared(void);
void IncrementNbFriendRescues(void);
uint32_t GetNbFriendRescues(void);
void IncrementNbEvolutions(void);
uint32_t GetNbEvolutions(void);
void IncrementNbSteals(void);
void IncrementNbEggsHatched(void);
uint32_t GetNbEggsHatched(void);
uint32_t GetNbPokemonJoined(void);
uint32_t GetNbMovesLearned(void);
void SetVictoriesOnOneFloor(uint32_t nb_victories);
uint32_t GetVictoriesOnOneFloor(void);
void SetPokemonJoined(enum monster_id monster_id);
void SetPokemonBattled(enum monster_id monster_id);
uint32_t GetNbPokemonBattled(void);
void IncrementNbBigTreasureWins(void);
void SetNbBigTreasureWins(uint32_t nb_big_treasure_wins);
uint32_t GetNbBigTreasureWins(void);
void SetNbRecycled(uint32_t nb_recycled);
uint32_t GetNbRecycled(void);
void IncrementNbSkyGiftsSent(void);
void SetNbSkyGiftsSent(uint32_t nb_sky_gifts_sent);
uint32_t GetNbSkyGiftsSent(void);
void ComputeSpecialCounters(void);
void RecruitSpecialPokemonLog(enum monster_id monster_id);
void IncrementNbFainted(void);
uint32_t GetNbFainted(void);
void SetItemAcquired(struct item* item);
uint32_t GetNbItemAcquired(void);
void SetChallengeLetterCleared(uint32_t challenge_id);
uint32_t GetSentryDutyGamePoints(int32_t rank);
int32_t SetSentryDutyGamePoints(uint32_t points);
void CopyLogTo(undefined* write_info);
void CopyLogFrom(undefined* read_info);
void GetAbilityString(undefined* buf, enum ability_id ability_id);
int GetAbilityDescStringId(enum ability_id ability_id);
int GetTypeStringId(enum type_id type_id);
enum type_id GetConversion2ConvertToType(enum type_id attack_type_id);
void CopyBitsTo(undefined* write_info, void* buf_write, int nbits);
void CopyBitsFrom(undefined* read_info, void* buf_read, int nbits);
void StoreDefaultTeamData(void);
void GetMainTeamNameWithCheck(char* buf);
void GetMainTeamName(char* buf);
void SetMainTeamName(char* buf);
int GetRankupPoints(void);
enum rank GetRank(void);
int GetRankStorageSize(void);
void ResetPlayTimer(struct play_time* igt);
void PlayTimerTick(struct play_time* igt);
uint32_t GetPlayTimeSeconds(struct play_time* igt);
uint32_t SubFixedPoint(uint32_t val_fp, uint32_t dec_fp);
uint32_t BinToDecFixedPoint(ufx32_16* q16);
int CeilFixedPoint(uint32_t val_fp);
bool DungeonGoesUp(enum dungeon_id dungeon_id);
int GetTurnLimit(enum dungeon_id dungeon_id);
bool DoesNotSaveWhenEntering(enum dungeon_id dungeon_id);
bool TreasureBoxDropsEnabled(enum dungeon_id dungeon_id);
bool IsLevelResetDungeon(enum dungeon_id dungeon_id);
int GetMaxItemsAllowed(enum dungeon_id dungeon_id);
bool IsMoneyAllowed(enum dungeon_id dungeon_id);
int8_t GetMaxRescueAttempts(enum dungeon_id dungeon_id);
bool IsRecruitingAllowed(enum dungeon_id dungeon_id);
bool GetLeaderChangeFlag(enum dungeon_id dungeon_id);
int16_t GetRandomMovementChance(enum dungeon_id dungeon_id);
bool CanEnemyEvolve(enum dungeon_id dungeon_id);
int GetMaxMembersAllowed(enum dungeon_id dungeon_id);
bool IsIqEnabled(enum dungeon_id dungeon_id);
bool IsTrapInvisibleWhenAttacking(enum dungeon_id dungeon_id);
bool JoinedAtRangeCheck(struct dungeon_id_8 joined_at);
bool IsDojoDungeon(enum dungeon_id dungeon_id);
bool IsFutureDungeon(enum dungeon_id dungeon_id);
bool IsSpecialEpisodeDungeon(enum dungeon_id dungeon_id);
enum item_id RetrieveFromItemList1(undefined* dungeon_info, undefined4 param_2);
bool IsForbiddenFloor(undefined* dungeon_info, undefined4 param_2, undefined4 param_3,
                      undefined4 param_4);
void Copy16BitsFrom(undefined* read_info, void* buf_read);
enum item_id RetrieveFromItemList2(undefined* dungeon_info, undefined4 param_2);
bool IsInvalidForMission(enum dungeon_id dungeon_id);
bool IsExpEnabledInDungeon(enum dungeon_id dungeon_id);
bool IsSkyExclusiveDungeon(enum dungeon_id dungeon_id);
bool JoinedAtRangeCheck2(struct dungeon_id_8 joined_at);
uint32_t GetBagCapacity(int scenario_balance);
uint32_t GetBagCapacitySpecialEpisode(int se_type);
struct rankup_table_entry* GetRankUpEntry(int rank);
int GetBgRegionArea(int offset, int subregion_id, int region_id);
void LoadMonsterMd(void);
void GetNameRaw(char* dst, enum monster_id monster_id);
void GetName(char* dst, enum monster_id monster_id, char color_id);
void GetNameWithGender(char* dst, enum monster_id monster_id, char color_id);
void GetSpeciesString(char* dst, enum monster_id monster_id);
char* GetNameString(enum monster_id monster_id);
int GetSpriteIndex(enum monster_id monster_id);
int GetDexNumber(enum monster_id monster_id);
char* GetCategoryString(enum monster_id monster_id);
enum monster_gender GetMonsterGender(enum monster_id monster_id);
int GetBodySize(enum monster_id monster_id);
uint8_t GetSpriteSize(enum monster_id monster_id);
uint8_t GetSpriteFileSize(enum monster_id monster_id);
int GetShadowSize(enum monster_id monster_id);
int GetSpeedStatus(enum monster_id monster_id);
enum mobility_type GetMobilityType(enum monster_id monster_id);
int GetRegenSpeed(enum monster_id monster_id);
bool GetCanMoveFlag(enum monster_id monster_id);
int GetChanceAsleep(enum monster_id monster_id);
fx32_8 GetWeightMultiplier(enum monster_id monster_id);
int GetSize(enum monster_id monster_id);
int GetBaseHp(enum monster_id monster_id);
bool CanThrowItems(enum monster_id monster_id);
bool CanEvolve(enum monster_id monster_id);
enum monster_id GetMonsterPreEvolution(enum monster_id monster_id);
int GetBaseOffensiveStat(enum monster_id monster_id, int stat_idx);
int GetBaseDefensiveStat(enum monster_id monster_id, int stat_idx);
int GetType(enum monster_id monster_id, int type_idx);
int GetAbility(enum monster_id monster_id, int ability_idx);
int GetRecruitRate2(enum monster_id monster_id);
int GetRecruitRate1(enum monster_id monster_id);
int GetExp(enum monster_id monster_id, int level);
void GetEvoParameters(undefined* evo_params, enum monster_id monster_id);
void GetTreasureBoxChances(enum monster_id monster_id, undefined* chances);
int GetIqGroup(enum monster_id monster_id);
int GetSpawnThreshold(enum monster_id monster_id);
bool NeedsItemToSpawn(enum monster_id monster_id);
int GetExclusiveItem(enum monster_id monster_id, int excl_idx);
int GetFamilyIndex(enum monster_id monster_id);
void LoadM2nAndN2m(void);
void GuestMonsterToGroundMonster(struct ground_monster* ground_monster,
                                 struct guest_monster* guest_monster);
void SetBaseStatsMovesGroundMonster(struct ground_monster* ground_monster);
bool StrcmpMonsterName(char* string, enum monster_id monster_id);
void GetLvlUpEntry(struct level_up_entry* level_up_entry, enum monster_id monster_id, int level);
uint8_t* GetEncodedHalfword(uint8_t* data_ptr, uint16_t* result);
int GetEvoFamily(undefined* monster, undefined* evo_family);
int GetEvolutions(enum monster_id monster_id, enum monster_id* output_list,
                  bool skip_sprite_size_check, bool skip_shedinja_check);
void ShuffleHiddenPower(undefined* dmons_addr);
enum monster_id GetBaseForm(enum monster_id);
enum monster_id GetBaseFormBurmyWormadamShellosGastrodonCherrim(enum monster_id monster_id);
enum monster_id GetBaseFormCastformCherrimDeoxys(enum monster_id monster_id);
int GetAllBaseForms(enum monster_id monster_id);
int GetDexNumberVeneer(enum monster_id monster_id);
enum monster_id GetMonsterIdFromSpawnEntry(struct monster_spawn_entry*);
void SetMonsterId(struct monster_spawn_entry* monster_spawn, enum monster_id monster_id);
void SetMonsterLevelAndId(struct monster_spawn_entry* monster_spawn, int level,
                          enum monster_id monster_id);
uint8_t GetMonsterLevelFromSpawnEntry(struct monster_spawn_entry* entry);
void ApplyLevelUpBoostsToGroundMonster(struct ground_monster* ground_monster, int level, bool flag);
enum monster_gender GetMonsterGenderVeneer(enum monster_id monster_id);
bool IsMonsterValid(enum monster_id monster_id);
bool IsUnown(enum monster_id monster_id);
bool IsShaymin(enum monster_id monster_id);
bool IsCastform(enum monster_id monster_id);
bool IsCherrim(enum monster_id monster_id);
bool IsDeoxys(enum monster_id monster_id);
enum monster_id GetSecondFormIfValid(enum monster_id monster_id);
enum monster_id FemaleToMaleForm(enum monster_id monster_id);
enum monster_id GetBaseFormCastformDeoxysCherrim(enum monster_id monster_id);
bool BaseFormsEqual(enum monster_id monster1, enum monster_id monster2);
bool DexNumbersEqual(enum monster_id monster1, enum monster_id monster2);
bool GendersEqual(enum monster_id monster1, enum monster_id monster2);
bool GendersEqualNotGenderless(enum monster_id monster1, enum monster_id monster2);
bool GendersNotEqualNotGenderless(enum monster_id monster1, enum monster_id monster2);
bool IsMonsterOnTeam(enum monster_id monster_id, int recruit_strategy);
void GetNbRecruited(undefined* recruit);
bool IsValidTeamMember(int member_idx);
bool IsMainCharacter(int member_idx);
struct ground_monster* GetTeamMember(int member_idx);
int GetHeroMemberIdx(void);
int GetPartnerMemberIdx(void);
int GetMainCharacter1MemberIdx(void);
int GetMainCharacter2MemberIdx(void);
int GetMainCharacter3MemberIdx(void);
struct ground_monster* GetHero(void);
struct ground_monster* GetPartner(void);
struct ground_monster* GetMainCharacter1(void);
struct ground_monster* GetMainCharacter2(void);
struct ground_monster* GetMainCharacter3(void);
int GetFirstMatchingMemberIdx(enum monster_id monster_id);
int GetFirstEmptyMemberIdx(int param_1);
bool IsMonsterNotNicknamed(struct ground_monster* monster);
void RemoveActiveMembersFromAllTeams(void);
void RemoveActiveMembersFromSpecialEpisodeTeam(void);
void RemoveActiveMembersFromRescueTeam(void);
bool CheckTeamMemberIdx(int member_idx);
bool IsMonsterIdInNormalRange(enum monster_id monster_id);
void SetActiveTeam(enum team_id team_id);
struct team_member* GetActiveTeamMember(int roster_idx);
int GetActiveRosterIndex(int member_idx);
int TryAddMonsterToActiveTeam(int member_idx);
void RemoveActiveMembersFromMainTeam(void);
void SetTeamSetupHeroAndPartnerOnly(void);
void SetTeamSetupHeroOnly(void);
int GetPartyMembers(uint16_t* party_members);
void RefillTeam(void);
int ClearItem(int team_id, bool check);
void ChangeGiratinaFormIfSkyDungeon(enum dungeon_id dungeon_id);
void RevertGiratinaAndShaymin(uint8_t member_idx, undefined param_2);
int GetIqSkillStringId(enum iq_skill_id iq_skill);
bool DoesTacticFollowLeader(enum tactic_id tactic_id);
void GetUnlockedTactics(enum tactic_id* unlocked_tactics, int level);
void GetUnlockedTacticFlags(bool* tactic_unlock_flags, int level);
bool CanLearnIqSkill(int iq_amount, enum iq_skill_id iq_id);
int GetLearnableIqSkills(struct iq_skill_id_8* out_iq_skill_id, enum monster_id monster_id,
                         int monster_iq);
void DisableIqSkill(uint32_t* iq_skills_flags, enum iq_skill_id iq_id);
void EnableIqSkill(uint32_t* iq_skills_flags, enum iq_skill_id iq_id);
enum iq_skill_id GetSpeciesIqSkill(enum monster_id monster_id, int index);
void DisableAllIqSkills(uint32_t* iq_skills_flags);
void EnableAllLearnableIqSkills(uint32_t* iq_skills_flags, enum monster_id monster_id,
                                int monster_iq);
bool IqSkillFlagTest(uint32_t* iq_skill_flags, enum iq_skill_id iq_id);
enum iq_skill_id GetNextIqSkill(enum monster_id monster_id, int monster_iq);
void GetExplorerMazeTeamName(char* buffer);
struct ground_monster* GetExplorerMazeMonster(uint8_t entry_number);
undefined4 WriteMonsterInfoToSave(void* start_addr, uint32_t total_len);
undefined4 ReadMonsterInfoFromSave(void* start_addr, uint32_t total_len);
void WriteMonsterToSave(undefined* write_info, struct ground_monster* monster);
void ReadMonsterFromSave(undefined* read_info, struct ground_monster* monster);
void GetEvolutionPossibilities(struct ground_monster* monster, undefined* evo);
int GetMonsterEvoStatus(struct ground_monster* monster);
void CopyTacticString(char* buffer, enum tactic_id tactic_id);
void GetStatBoostsForMonsterSummary(struct monster_summary* monster_summary,
                                    enum monster_id monster_id, struct item* item, int iq,
                                    bool klutz_active);
void CreateMonsterSummaryFromTeamMember(struct monster_summary* monster_summary,
                                        struct team_member* team_member, bool is_leader);
int GetSosMailCount(int param_1, bool param_2);
bool IsMissionSuspendedAndValid(struct mission* mission);
bool AreMissionsEquivalent(struct mission* mission1, struct mission* mission2);
bool IsMissionValid(struct mission* mission);
enum mission_generation_result GenerateMission(undefined* param_1, struct mission* mission_data);
bool IsMissionTypeSpecialEpisode(struct mission* mission);
void GenerateDailyMissions(void);
bool AlreadyHaveMission(struct mission* mission);
int CountJobListMissions(void);
int DungeonRequestsDone(uint8_t param_1, bool param_2);
int DungeonRequestsDoneWrapper(uint8_t param_1);
bool AnyDungeonRequestsDone(uint8_t param_1);
void AddMissionToJobList(struct mission* mission);
struct mission* GetAcceptedMission(uint8_t mission_id);
int GetMissionByTypeAndDungeon(int start_index, enum mission_type mission_type,
                               undefined* subtype_struct, enum dungeon_id dungeon_id);
bool CheckAcceptedMissionByTypeAndDungeon(enum mission_type mission_type, undefined* subtype_struct,
                                          enum dungeon_id dungeon_id);
int GetAllPossibleMonsters(void* buf);
int GenerateAllPossibleMonstersList(void);
void DeleteAllPossibleMonstersList(void);
int GenerateAllPossibleDungeonsList(void);
void DeleteAllPossibleDungeonsList(void);
int GenerateAllPossibleDeliverList(void);
void DeleteAllPossibleDeliverList(void);
void ClearMissionData(struct mission* mission);
void GenerateMissionDetailsStruct(struct mission* mission, struct mission_details* details,
                                  undefined param_3, undefined param_4);
bool ValidateNormalChallengeMission(struct mission_template* valid_mission_info,
                                    struct mission* mission);
bool ValidateLegendaryChallengeMission(struct mission_template* valid_mission_info,
                                       struct mission* mission);
void AppendMissionTitle(char* main_buffer, char* temp_buffer, struct preprocessor_args* args,
                        struct mission_details* details);
void AppendMissionSummary(char* main_buffer, char* temp_buffer, int window_id, int y_offset,
                          struct preprocessor_args* args, struct mission_details* details);
bool IsMonsterMissionAllowed(enum monster_id monster_id);
bool CanMonsterBeUsedForMissionWrapper(enum monster_id monster_id);
bool CanMonsterBeUsedForMission(enum monster_id monster_id, bool check_story_banned);
bool IsMonsterMissionAllowedStory(enum monster_id monster_id);
bool IsMonsterIllegalForMissions(enum monster_id monster_id);
bool CanDungeonBeUsedForMission(enum dungeon_id dungeon_id);
bool CanSendItem(enum item_id item_id, bool to_sky);
bool IsAvailableItem(enum item_id item_id);
int GetAvailableItemDeliveryList(undefined* item_buffer);
int GetActorMatchingStorageId(int actor_id);
void SetActorTalkMainAndActorTalkSub(int actor_id_main, int actor_id_sub);
void SetActorTalkMain(int actor_id);
void SetActorTalkSub(int actor_id);
void RandomizeDemoActors(void);
void ItemAtTableIdx(int idx, struct bulk_item* item);
void MainLoop(void);
void CreateJobSummary(struct mission* mission, int param_2);
int DungeonSwapIdToIdx(enum dungeon_id dungeon_id);
enum dungeon_id DungeonSwapIdxToId(int idx);
enum dungeon_mode GetDungeonModeSpecial(enum dungeon_id dungeon_id);

#endif
