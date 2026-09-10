Bootstrap uses a 12-column grid system. We can use responsive grid classes to control how many columns an article occupies at different screen sizes.

For the article column <div>, use:
	
	ex:
		<div class="col-12 col-md-4">
    Article
</div>

Explanation
col-12 ? On small/mobile screens, the article takes all 12 columns, so it appears in a single-column layout.
col-md-4 ? On medium and larger screens, the article takes 4 columns out of 12. Therefore, 3 articles fit in one row because 4 + 4 + 4 = 12.

So:

Mobile: 12/12 ? 1 article per row
Desktop: 4/12 ? 3 articles per row

No custom media query CSS is required.
