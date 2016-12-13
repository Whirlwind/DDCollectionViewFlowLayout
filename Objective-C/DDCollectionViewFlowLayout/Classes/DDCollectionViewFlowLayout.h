//
//  DDCollectionViewFlowLayout.h
//  DDCollectionViewFlowLayout
//
//  Created by DeJohn Dong on 15-2-12.
//  Copyright (c) 2015年 DDKit. All rights reserved.
//

#import <UIKit/UIKit.h>

@class  DDCollectionViewFlowLayout;

@protocol DDCollectionViewDelegateFlowLayout <UICollectionViewDelegateFlowLayout>

@optional
/**
 *  The delegate method set the collectionView will flow layout as the number columns in each section.
 *
 *  @param collectionView The effect collectionView
 *  @param layout         The DDCollectionViewFlowLayout inilization object.
 *  @param section        The section index
 *
 *  @return The number of columns in each section.
 */
- (NSInteger)collectionView:(UICollectionView *)collectionView
                     layout:(DDCollectionViewFlowLayout *)layout
   numberOfColumnsInSection:(NSInteger)section;

- (CGFloat)collectionView:(UICollectionView *)collectionView
                   layout:(DDCollectionViewFlowLayout *)layout
 heightForItemAtIndexPath:(NSIndexPath *)indexPath
            withItemWidth:(CGFloat)width;

@end

@interface DDCollectionViewFlowLayout : UICollectionViewFlowLayout

@property (nonatomic, weak) IBOutlet id<DDCollectionViewDelegateFlowLayout> delegate;

/**
 *  Defalut is NO, set it's YES the collectionView's header will sticky on the section top.
 */
@property (nonatomic) IBInspectable BOOL enableStickyHeaders;

/**
 *  Defalut is YES, set it's YES the collectionView's itemSize will reset the height to itemSize.height / itemSize.width * actualItemSize.width.
 */
@property (nonatomic) IBInspectable BOOL enableScaleItemSize;

/**
 *  Defalut is 3, set the number of columns.
 */
@property (nonatomic) IBInspectable NSUInteger numberOfColumns;

- (CGSize)actualSizeForItemAtIndexPath:(NSIndexPath *)indexPath;

@end
